#pragma once
//#include <Vector.h>
#include <Point.h>

namespace cgm{
    
    class Plane{
        
        private:
            Vector m_normal;
            float m_d = 0;
      
        public:
            Plane() = default;
            Plane(Vector normal, float d) : m_normal(m_normal), m_d(d){}
            
            Plane(Point3D p1, Point3D p2, Point3D p3)
            {
                auto v12 = p2 - p1;
                auto v13 = p3 - p1;
                
                m_normal = Vector::CrossProduct3D(v12, v13);
                m_d = Vector::DotProduct(m_normal, p1);
            }

            float d_point(){
                return m_d;
			}
        
    };
}