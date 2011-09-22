#include "scene.h"

scene::scene()
{
}
scene::~scene(){
	if(m_cCam)
		delete m_cCam;
	std::vector<light *>::iterator lit = m_vLights.begin();
	while(lit != m_vLights.end()){
		if((*lit))
			delete (*lit);
		++lit;
	}
	std::vector<scene_object *>::iterator soit = m_vSceneObjects.begin();
	while(soit != m_vSceneObjects.end()){
		if((*soit))
			delete (*soit);
		++soit;
	}

}
void scene::addLight(light *l){
	m_vLights.push_back(l);
}
void scene::addSceneObject(scene_object *s){
	m_vSceneObjects.push_back(s);
}

void scene::setCamera(camera *pCamera){
	m_cCam = pCamera;
}

std::vector<light *> *scene::getLights(){
	return &m_vLights;
}

std::vector<scene_object *> *scene::getSceneObjects(){
	return &m_vSceneObjects;
}
void scene::getCamera(camera &pCamera){
	pCamera = (*m_cCam);
}
camera * scene::getCamera(){
	return m_cCam;
}
