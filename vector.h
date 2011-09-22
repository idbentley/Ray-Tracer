#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
/* 3D Vector */
class vec3f{
	private:
		float m_vec[3];
	public:
		/*Constructors & Deconstructors*/
		vec3f(){
			m_vec[0] = 0.0f;
			m_vec[1] = 0.0f;
			m_vec[2] = 0.0f;
		}
		vec3f(float x, float y, float z){
			m_vec[0] = x;
			m_vec[1] = y;
			m_vec[2] = z;

		}
		vec3f(const vec3f &old){
			m_vec[0] = old.m_vec[0];
			m_vec[1] = old.m_vec[1];
			m_vec[2] = old.m_vec[2];
		}
		~vec3f(){}
		/*Procedures*/
		vec3f& operator=(const vec3f&);
		vec3f operator-(const vec3f&) const;
		vec3f operator+(const vec3f&) const;
		vec3f operator*(float ) const;
		vec3f operator*(vec3f ) const;
		vec3f operator/(float ) const;
		float operator[](const int ) const;
		float& operator[](const int );
		vec3f cross(const vec3f&) const;
		float dot(const vec3f&) const;
		float distance(const vec3f&) const;
		vec3f reflect(const vec3f&) const;
		void normalize();
		std::string colorPrint();
};

std::ostream& operator<<(std::ostream & o, const vec3f &v);

#endif //VECTOR_H
