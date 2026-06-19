#include "Line.h"

void cgm::Line::setDirection(Point3D & dir)
{
    m_dir.assign(X, dir);
    // m_dir.assign(Y, dir[Y]);
    // m_dir.assign(Z, dir[Z]);
    
    return;
}

void cgm::Line::setPoint(Point3D & iPoint)
{
    m_point.assign(X, iPoint);
    // m_point.assign(Y, iPoint[Y]);
    // m_point.assign(Z, iPoint[Z]);
    
    return;
}


cgm::Point3D cgm::Line::direction() const
{
	return m_dir;
}

cgm::Point3D cgm::Line::point() const
{
	return m_point;
}