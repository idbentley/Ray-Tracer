#include <string>
#include <iostream>
#include <fstream>

#include "vector.h"

#include "scene.h"

#include "light.h"
#include "point_light.h"
#include "directional_light.h"

#include "scene_object.h"
#include "sphere.h"

#include "camera.h"
#include "eye.h"
#include "ray.h"

//GLOBALS

std::ofstream ppmfile;


void init_scene(scene *, int, int);
vec3f *trace_pixel_std(vec3f pPos, camera *c, float pPixelHeight, float pPixelWidth, scene *s, int recursionIndex);
void ray_trace(int xPixels, int yPixels, scene *s, vec3f *(*trace_pixel) (vec3f, camera *, float, float, scene *, int), int recursionIndex);
void init_scene(scene *pScene, int xPixels, int yPixels)
{
	//Set up a camera.	
	camera *c = new camera(vec3f(0.0f, 0.0f, -40.0f), vec3f(0.0f, 1.0f, 0.0f), vec3f(0.0f, 0.0f, -1.0f), xPixels, yPixels, 3.0f); 
	//Define scene objects and lights.
	point_light *l1 = new point_light(vec3f(0.0f, 0.0f, -100.0f), vec3f(0.1f, 0.1f, 0.1f), vec3f(0.2f, 0.2f, 0.2f), vec3f(0.8f, 0.8f, 0.8f));
	directional_light *l2 = new directional_light(vec3f(0.5f, 0.5f, 0.0f), vec3f(0.2f, 0.05f, 0.05f), vec3f(0.4f, 0.1f, 0.1f), vec3f(0.8f, 0.6f, 0.6f));
	sphere *s1 = new sphere(vec3f(15.0f, 0.0f, 10.0f), 5.0f, color(vec3f(0.4f, 0.0f, 0.0f), vec3f(0.5f, 0.0f, 0.0f), vec3f(0.8f, 0.8f, 0.8f)), 200.0f);
	sphere *s2 = new sphere(vec3f(0.0f, 0.0f, 0.0f), 5.0f,	color(vec3f(0.0f, 0.0f, 0.4f), vec3f(0.0f, 0.0, 0.6f), vec3f(0.3f, 0.3f, 0.3f)), 500.0f);
	//Add to scene;
	pScene->setCamera(c);
	pScene->addLight(l1);
	pScene->addLight(l2);
	pScene->addSceneObject(s1);
	pScene->addSceneObject(s2);
}

int main(int argc, char **argv)
{
	scene *s = new scene();
	int xPixels = 500, yPixels = 500;
	init_scene(s, xPixels, yPixels);
	ppmfile.open("output.ppm");
	//Write the ppm header.
	ppmfile << "P3" << std::endl << xPixels << " " << yPixels << std::endl << 255 << std::endl;
	ray_trace(xPixels, yPixels, s, trace_pixel_std, 1);
	delete s;
	return 0;
}

void ray_trace(int xPixels, int yPixels, scene *s, vec3f *(*trace_pixel) (vec3f, camera *, float, float, scene *, int), int recursionIndex){
	camera *c;
	c = s->getCamera();
	vec3f ***pixels = new vec3f **[yPixels];
	for(int i = 0; i < yPixels; i++)
		pixels[i] = new vec3f *[xPixels];
	float pixelHeight = c->getPixelHeight();
	float pixelWidth = c->getPixelWidth();
	for(int i = 0; i < yPixels; i++){
		for(int j = 0; j < xPixels; j++){
				pixels[i][j] = trace_pixel(c->getPixelPos(j, i), c, pixelHeight, pixelWidth, s, recursionIndex);
				ppmfile << pixels[i][j]->colorPrint() << " ";
				delete pixels[i][j];
		}
		delete [] pixels[i];
		ppmfile << std::endl;
	}
	delete [] pixels;
}


vec3f *trace_pixel_std(vec3f pPos, camera *c, float pPixelHeight, float pPixelWidth, scene *s, int recursionIndex){
	eye e;
	c->getEye(e);
	ray *r = new ray(pPos, e.getPos());
	vec3f *v = r->trace(s, recursionIndex);
	delete r;
	return v;
}
