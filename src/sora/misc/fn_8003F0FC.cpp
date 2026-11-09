#include <mt/mt_matrix.h>
#include <mt/mt_trig.h>

#pragma force_active on

void Matrix::setSRT(const Vec3f& p1, const Vec3f& p2, const Vec3f& p3) {
    float sinX, sinY, sinZ;
    float cosX, cosY, cosZ;

    mtSinCosf(p2.m_x, &sinX, &cosX);
    mtSinCosf(p2.m_y, &sinY, &cosY);
    mtSinCosf(p2.m_z, &sinZ, &cosZ);

    this->_00 = p1.m_x * (cosY * cosZ);
    this->_10 = p1.m_x * (cosY * sinZ);
    this->_20 = -sinY * p1.m_x;
    this->_01 = p1.m_y * (cosZ * (sinX * sinY) - (cosX * sinZ));
    this->_11 = p1.m_y * (sinZ * (sinX * sinY) + (cosX * cosZ));
    this->_21 = p1.m_y * (sinX * cosY);
    this->_02 = p1.m_z * (cosZ * (cosX * sinY) + (sinX * sinZ));
    this->_12 = p1.m_z * ((cosX * sinY) * sinZ - (sinX * cosZ));
    this->_22 = p1.m_z * (cosX * cosY);
    this->_03 = p3.m_x;
    this->_13 = p3.m_y;
    this->_23 = p3.m_z;
}