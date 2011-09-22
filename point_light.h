#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "light.h"


class point_light : public light{
private:
protected:
	vec3f m_vPoint;
public:
	point_light(vec3f pPoint, vec3f pAmbient, vec3f pDiffuse, vec3f pSpecular);
	vec3f getToLight(poi *p);
	float getDistToLight(poi *p);
	ray getRayToLight(poi *p);
};

#endif //POINT_LIGHT_H
