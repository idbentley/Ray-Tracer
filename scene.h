#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "camera.h"
#include "scene_object.h"
#include "light.h"


class scene_object;
class light;
class scene{
private:
	camera *m_cCam;
	std::vector<light *> m_vLights;
	std::vector<scene_object *> m_vSceneObjects;
public:
	scene();
	~scene();
	void addLight(light *);
	void addSceneObject(scene_object *);
	void setCamera(camera *);
	std::vector<light *> *getLights();
	std::vector<scene_object *> *getSceneObjects();
	void getCamera(camera &);
	camera *getCamera();
};


#endif //SCENE_H

