#pragma once
//#include <Vector.h>
#include <Point.h>

namespace cgm
{
    
    class Line
    {
        public:
        
        Point3D m_dir;
        Point3D m_point;
        
        Point3D m_StartPoint;
		Point3D m_EndPoint;

        Line() = default;
        
        
        Line(Point3D p1, Point3D p2)
        {
            m_dir = p2 - p1;
            m_point = p1;
            m_StartPoint = p1;
			m_EndPoint = p2;
        }


        void setDirection(Point3D&);
        void setPoint(Point3D&);
        Point3D point()const ;
        Point3D direction()const;
        
        
    };
}

