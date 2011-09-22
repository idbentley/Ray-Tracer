#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include "ray_tracer.h"
#include "vector.h"
#include "ray.h"
#include "scene.h"

//struct color_triplet;
//typedef color_triplet color;
class ray;
class scene;
class scene_object{
private:
protected:
	color m_cColor;
	float m_fAlpha;
public:
	scene_object(color pColor, float pAlpha): m_cColor(pColor), m_fAlpha(pAlpha){
	}
	virtual poi rayIntersect(ray *, scene *) = 0;
	virtual color phongShade(poi *i, scene *, int );
};



#endif // SCENE_OBJECT_H
