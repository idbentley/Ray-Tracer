#include "sphere.h"

#include <cmath>
#include <limits>

sphere::sphere(vec3f pCenter, float pRadius, color pColor, float pAlpha) :
	scene_object(pColor, pAlpha), m_vCenter(pCenter), m_fRadius(pRadius)
{
}
sphere::~sphere()
{
}
poi sphere::rayIntersect(ray *r, scene *s){
	poi p;

	vec3f dst = r->getTail() - m_vCenter;
	float b = dst.dot(r->getDirection());
	float c = dst.dot(dst) - pow(m_fRadius, 2);
	float d = b * b  - c;
	if(d > 0){
		p.hit = true;
		p.distance = (-b - sqrt(d));
		p.point = r->getTail() + r->getDirection()*p.distance;
		p.normal = p.point - m_vCenter;
	}else{
		p.hit = false;
		p.distance = std::numeric_limits<float>::infinity();
	}
	return p;
}
