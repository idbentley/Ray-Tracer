#include "light.h"

light::light(vec3f pAmbient, vec3f pDiffuse, vec3f pSpecular)
	: m_cAmbient(pAmbient), m_cDiffuse(pDiffuse), m_cSpecular(pSpecular)
{

}

light::~light(){
}

vec3f light::getAmbient(){
	return m_cAmbient;
}

vec3f light::getDiffuse(){
	return m_cDiffuse;
}

vec3f light::getSpecular(){
	return m_cSpecular;
}
