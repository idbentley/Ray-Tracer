#include "vector.h"
#include <ostream>
#include <cmath>
#include <sstream>
#include <string>

/* -- vec3f -- */

/*Procedures*/

vec3f vec3f::operator+ (const vec3f& second) const{
	vec3f temp;
	temp[0] = second[0]+m_vec[0];
	temp[1] = second[1]+m_vec[1];
	temp[2] = second[2]+m_vec[2];
	return temp;
}

vec3f vec3f::operator- (const vec3f& second) const{
	vec3f temp;
	temp[0] = m_vec[0]-second[0];
	temp[1] = m_vec[1]-second[1];
	temp[2] = m_vec[2]-second[2];
	return temp;
}
vec3f vec3f::operator* (float m) const{
	vec3f temp;
	temp[0] = m_vec[0]*m;
	temp[1] = m_vec[1]*m;
	temp[2] = m_vec[2]*m;
	return temp;
}
vec3f vec3f::operator* (vec3f v) const{
	vec3f temp;
	temp[0] = m_vec[0]*v[0];
	temp[1] = m_vec[1]*v[1];
	temp[2] = m_vec[2]*v[2];
	return temp;
}
vec3f& vec3f::operator=(const vec3f& v){
	m_vec[0] = v[0];
	m_vec[1] = v[1];
	m_vec[2] = v[2];
	return *this;
}
vec3f vec3f::operator/(float m) const{
	vec3f temp;
	temp[0] = m_vec[0]/m;
	temp[1] = m_vec[1]/m;
	temp[2] = m_vec[2]/m;
	return temp;
}
float vec3f::operator[](const int i) const{
	return m_vec[i];
}
float& vec3f::operator[](const int i){
	return m_vec[i];
}
vec3f vec3f::cross(const vec3f& v) const{
	vec3f temp;
	temp[0] = m_vec[1]*v[2]-m_vec[2]*v[1];
	temp[1] = m_vec[2]*v[0]-m_vec[0]*v[2];
	temp[2] = m_vec[0]*v[1]-m_vec[1]*v[0];
	return temp;
}

float vec3f::dot(const vec3f& v) const{
	return m_vec[0]*v[0] + m_vec[1]*v[1] + m_vec[2]*v[2];
}

float vec3f::distance(const vec3f& v) const{
	return sqrt(pow(m_vec[0]-v[0], 2)+pow(m_vec[1]-v[1], 2)+pow(m_vec[2]-v[2], 2));
}
void vec3f::normalize(){
	float f = this->distance(vec3f());
	(*this) = (*this)*(1/f);
}
vec3f vec3f::reflect(const vec3f& v) const{
	vec3f temp;
	float tmp = 2.0 * (v.dot((*this)));
	temp = (*this)*tmp - v;
	return temp;
}

std::string vec3f::colorPrint(){
	std::ostringstream o;
	o << std::max(std::min(static_cast<int>(m_vec[0]*255), 255), 0) << " " << std::max(std::min(static_cast<int>(m_vec[1]*255), 255), 0) << " " << std::max(std::min(static_cast<int>(m_vec[2]*255), 255), 0);
	return o.str();
}

std::ostream& operator<<(std::ostream& o, const vec3f &v){ 
	o << "[ " << v[0] << ", " << v[1] << ", " << v[2] << "]"; 
	return o;
}
