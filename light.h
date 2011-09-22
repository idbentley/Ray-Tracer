#ifndef LIGHT_H
#define LIGHT_H

#include "ray_tracer.h"
#include "ray.h"

//struct point_of_intersection;
//typedef point_of_intersection poi;
class ray;
class light{
private:
protected:
	vec3f m_cAmbient;
	vec3f m_cDiffuse;
	vec3f m_cSpecular;
public:
	light(vec3f, vec3f, vec3f);
	~light();
	virtual vec3f getToLight(poi *p)=0;
	virtual float getDistToLight(poi *p)=0;
	virtual ray getRayToLight(poi *p)=0;
	vec3f getAmbient();
	vec3f getDiffuse();
	vec3f getSpecular();
};

#endif //LIGHT_H
