#include "scene_object.h"
#include <vector>
#include <cmath>
#include <iostream>

color scene_object::phongShade(poi *p, scene *s, int recursion){
	color c;
	std::vector<light *>::iterator it = s->getLights()->begin();
	while(it != s->getLights()->end()){
		/*
		 * if a shadow is detected, go to next light.
		 */
		/*ray r = (*it)->getRayToLight(p);
		poi shadowcheck = r.tracePOI(s);
		if( shadowcheck.hit && ( shadowcheck.distance < (*it)->getDistToLight(p) ) && shadowcheck.object != p->object ){
			++it;
			continue;
		}*/
		/*
		 * l - Direction vec to light
		 * n - Normal at poi
		 * h - Halfway vector for Blinn-Phong
		 * rf - Reflection vector
		 * v - Direction vec to camera
		 */
		vec3f l, n, h, v, rf;
		l = (*it)->getToLight(p);
		n = p->normal;
		l.normalize();
		n.normalize();
		h = l + v;
		h = h / h.distance(vec3f());
		rf = v.reflect(n);
		rf.normalize();
		eye e;
		s->getCamera()->getEye(e);
		v = e.getPos() - p->point;
		v.normalize();
		/*
		 * do reflection.
		 */
		float alpha = m_fAlpha;
		vec3f *refCol = NULL;
		if(recursion > 0){
			ray r = ray(p->point + rf*2.0f, p->point + rf);
			refCol = r.trace(s, recursion - 1);
			(*refCol) = (*refCol)*0.8f;//*(alpha/1000.0f);
		}
		vec3f tmpamb = (*it)->getAmbient();
		c.ambient = c.ambient + tmpamb*m_cColor.ambient;
		vec3f tmpdif = (*it)->getDiffuse();
		c.diffuse = c.diffuse + tmpdif*m_cColor.diffuse*std::max(0.0f, l.dot(n));
		vec3f tmpspec = (*it)->getSpecular();
		c.specular = c.specular + tmpspec*m_cColor.specular*pow(std::max(0.0f, n.dot(h)), alpha); 
		/*
		 * add reflection to the ambient color.  Needs to go somewhere.
		 */
		if(refCol){
			c.ambient = c.ambient + (*refCol);
			delete refCol;
		}
		++it;
	}
	return c;
}
