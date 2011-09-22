#include "directional_light.h"
#include <limits>
directional_light::directional_light(vec3f pDirection, vec3f pAmbient, vec3f pDiffuse, vec3f pSpecular)
	: light( pAmbient, pDiffuse, pSpecular ), m_vDirection(pDirection)
{
}

vec3f directional_light::getToLight(poi *p){
	return m_vDirection;
}
ray directional_light::getRayToLight(poi *p){
	return ray(m_vDirection, vec3f(0.0f, 0.0f, 0.0f));
}

float directional_light::getDistToLight(poi *p){
	return std::numeric_limits<float>::infinity();
}
