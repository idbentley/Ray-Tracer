#ifndef SPHERE_H
#define SPHERE_H

#include "ray_tracer.h"
#include "scene_object.h"
#include "ray.h"

class sphere : public scene_object{
private:
	vec3f m_vCenter;
	float m_fRadius;

public:
	sphere(vec3f pCenter, float pRadius, color pColor, float shininess);
	~sphere();
	poi rayIntersect(ray *, scene *);


};

#endif // SPHERE_H
