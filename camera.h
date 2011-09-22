#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"
#include "eye.h"
#include <cmath>

class camera{
public:
	camera(){}
	camera(vec3f pPos, vec3f pUp, vec3f pForward, int pXPixels, int pYPixels, float pDist) : m_fDist(pDist), m_iXPixels(pXPixels), m_iYPixels(pYPixels), m_eEye(pPos, pUp, pForward)
	{
		rebuildPlane();
	}
	~camera();
	float getPlaneAngle();
	void getEye(eye &);
	vec3f getPixelPos(int x, int y);
	float getPixelHeight();
	float getPixelWidth();
	
	void setDist(float );
	void setEye(eye );
	
private:
	//Distance from camera to plane.
	float m_fDist;
	float m_fWidth;
	float m_fHeight;
	int m_iXPixels;
	int m_iYPixels;
	vec3f m_vBotLeft;
	vec3f m_vTopLeft;
	vec3f m_vBotRight;
	vec3f m_vTopRight;
	eye m_eEye;

	/* Functions */
	void rebuildPlane();
};


#endif //CAMERA_H
