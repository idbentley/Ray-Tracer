#include "camera.h"
#include <iostream>
camera::~camera(){
	
}

/*
 * Accessors
 */
void camera::getEye(eye &e){
	e = m_eEye;
}

vec3f camera::getPixelPos(int x, int y){
	float xRatio = static_cast<float>(x) / static_cast<float>(m_iXPixels);
	float yRatio = static_cast<float>(y) / static_cast<float>(m_iYPixels);
	vec3f xDiffVec = m_vTopRight - m_vTopLeft;
	vec3f yDiffVec = m_vTopLeft - m_vBotLeft;
	return m_vBotLeft + (xDiffVec * xRatio) + (yDiffVec * yRatio);
}

float camera::getPixelHeight(){
	return m_fHeight / m_iYPixels;	
}

float camera::getPixelWidth(){
	return m_fWidth / m_iXPixels;
}

/*
 * Mutators
 */
void camera::setDist(float pDist){
	m_fDist = pDist;
	rebuildPlane();
}
void camera::setEye(eye pEye){
	m_eEye = pEye;
	rebuildPlane();
}



void camera::rebuildPlane(){
	m_eEye.getUp().normalize();
	m_eEye.getForward().normalize();
	/*
	 * We want the width and height of the viewing plane to be between 1 and 10
	 * This is an arbitrary decision made so that values of dist can be nice
	 * So we normalize the values so that the smallest one is less than 10.
	 * Maybe we shouldn't bother, but we do.  so there.
	 */
	m_fWidth = static_cast<float>(m_iXPixels);
	m_fHeight = static_cast<float>(m_iYPixels);
	float tmp = std::min(m_fWidth, m_fHeight);
	float scaleConst = 1.0f;
	while(tmp > 10.0f){
		scaleConst *= 10.0f;
		tmp /= 10.0f;
	}
	m_fWidth /= scaleConst;
	m_fHeight /= scaleConst;
	float wtmp = m_fWidth / 2.0f;
	float htmp = m_fHeight / 2.0f;
	vec3f newPos = m_eEye.getPos() + m_eEye.getForward()*m_fDist;
	m_vBotLeft = newPos - m_eEye.getUp()*htmp - m_eEye.getUp().cross(m_eEye.getForward())*wtmp;
	m_vTopLeft = newPos + m_eEye.getUp()*htmp - m_eEye.getUp().cross(m_eEye.getForward())*wtmp;
	m_vBotRight = newPos - m_eEye.getUp()*htmp + m_eEye.getUp().cross(m_eEye.getForward())*wtmp;
	m_vTopRight = newPos + m_eEye.getUp()*htmp + m_eEye.getUp().cross(m_eEye.getForward())*wtmp;
	std::cout << m_vBotLeft << " " << m_vTopLeft << m_vBotRight << " " << m_vTopRight << std::endl;
}

