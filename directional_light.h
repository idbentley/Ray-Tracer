#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "light.h"

class directional_light : public light{
private:
protected:
	vec3f m_vDirection;
public:
	directional_light(vec3f pDirection, vec3f pAmbient, vec3f pDiffuse, vec3f pSpecular);
	vec3f getToLight(poi *p);
	float getDistToLight(poi *p);
	ray getRayToLight(poi *p);

};


#endif //DIRECTIONAL_LIGHT_H
