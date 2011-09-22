#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include "vector.h"

struct color_triplet{
	vec3f ambient;
	vec3f diffuse;
	vec3f specular;
	color_triplet(vec3f pAmbient, vec3f pDiffuse, vec3f pSpecular) : ambient(pAmbient), diffuse(pDiffuse), specular(pSpecular)   {}
	color_triplet() : ambient(vec3f(0.0f,0.0f,0.0f)), diffuse(vec3f(0.0f,0.0f,0.0f)), specular(vec3f(0.0f,0.0f,0.0f)){}
};

struct point_of_intersection{
	bool hit;
	float distance;
	vec3f point;
	vec3f normal;
	color_triplet col;
	void *object;
};

typedef point_of_intersection poi;
typedef color_triplet color;
#endif  //RAY_TRACER_H
