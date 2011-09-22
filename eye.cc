#include "eye.h"


/*
 * Accessors
 */
vec3f eye::getPos(){
	return m_vPos;
}

vec3f eye::getUp(){
	return m_vUp;
}

vec3f eye::getForward(){
	return m_vForward;
}

/*
 * Mutators
 */
void eye::setPos(vec3f pPos){
	m_vPos = pPos;
}
void eye::setUp(vec3f pUp){
	m_vUp = pUp;
}
void eye::setForward(vec3f pForward){
	m_vForward = pForward;
}
