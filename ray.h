#ifndef RAY_H
#define RAY_H

#include "ray_tracer.h"
#include "vector.h"
#include "scene.h"
class scene;
class ray{
public:
	ray(vec3f pTip, vec3f pTail) : m_vTip(pTip), m_vTail(pTail)
	{
	}
	~ray()
	{
	}
	/*
	 * trace takes in a scene object, and a recursion constant.  
	 * If the constant is 0, do not recurse further, 
	 * if the constant is 1 or higher, continue reflection casting.
	 */
	vec3f *trace(scene *s, int r);
	vec3f getTip();
	vec3f getTail();
	vec3f getDirection();
	poi tracePOI(scene *s);
private:
	vec3f m_vTip;
	vec3f m_vTail;

};


#endif //RAY_H
