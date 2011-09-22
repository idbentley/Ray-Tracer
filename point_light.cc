#include "point_light.h"
#include <iostream>

point_light::point_light(vec3f pPoint, vec3f pAmbient, vec3f pDiffuse, vec3f pSpecular)
	: light( pAmbient, pDiffuse, pSpecular ), m_vPoint(pPoint)
{
}

vec3f point_light::getToLight(poi *p){
	return m_vPoint - p->point;
}
ray point_light::getRayToLight(poi *p){
	return ray(m_vPoint, p->point);
}
float point_light::getDistToLight(poi *p){
	return m_vPoint.distance(p->point);
}
