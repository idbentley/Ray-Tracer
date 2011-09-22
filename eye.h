#ifndef EYE_H
#define EYE_H

#include "vector.h"

class eye{
public:
	eye(vec3f pPos, vec3f pUp, vec3f pForward):
	m_vPos(pPos), m_vUp(pUp), m_vForward(pForward)
	{
	}
	eye(){}
	~eye(){
	}
	vec3f getPos();
	vec3f getUp();
	vec3f getForward();
	void setPos(vec3f );
	void setUp(vec3f );
	void setForward(vec3f );
	void setPlaneAngle(float );
private:
	vec3f m_vPos;
	vec3f m_vUp;
	vec3f m_vForward;
};

#endif // EYE_H
