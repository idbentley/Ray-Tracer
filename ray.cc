#include "ray.h"
#include <iostream>
#include <vector>
#include "scene_object.h"

vec3f ray::getTip(){
	return m_vTip;
}

vec3f ray::getTail(){
	return m_vTail;
}
vec3f ray::getDirection(){
	vec3f tmp = m_vTip-m_vTail;
	tmp.normalize();
	return tmp;
}
vec3f *ray::trace(scene *s, int r){
	poi closest;
	closest = tracePOI(s);
	vec3f c;
	if(closest.hit){
		closest.col = static_cast<scene_object *>(closest.object)->phongShade(&closest, s, r);
		c = vec3f(closest.col.ambient + closest.col.diffuse + closest.col.specular);
	}
	//Gets freed in ray_trace.
	return new vec3f(c);
}
poi ray::tracePOI(scene *s){
	poi closest, p;
	closest.hit = false;
	std::vector<scene_object *>::iterator it = s->getSceneObjects()->begin();
	while( it != s->getSceneObjects()->end()){
		p = (*it)->rayIntersect(this, s);
		p.object = (*it);
		if(p.hit && (p.distance < closest.distance || !closest.hit))
		{
			closest = p;
		}
		++it;	
	}
	return closest;
}
