#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <nw4r/math/math_types.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on

extern const float lbl_46_rodata_140;
extern const float lbl_46_rodata_144;

class Class_1F30 {
public:
    virtual void fn_46_61D8();
    virtual void fn_46_6258();
    virtual void fn_46_680C();
    virtual void fn_46_6808();
    virtual void fn_46_6804();
    virtual void fn_46_6800();
    virtual void fn_46_6218(nw4r::g3d::ScnMdlSimple*);
    virtual void fn_46_67E0(float, float, float);
    virtual void fn_46_67F0(float, float, float);
};

extern "C" void fn_46_6640(unsigned char* self) {
    unsigned char* p = self + 0xd0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(self + 0x44);
        nw4r::g3d::ScnMdlSimple* m = *(nw4r::g3d::ScnMdlSimple**)a;
        if (m != 0) {
            if (m->m_calcWorldCallBack == 0) {
                *(unsigned int*)(p + 0xc) = 0;
                unsigned int* q = *(unsigned int**)(p + 4);
                *q = *(unsigned int*)(self + 0xc4);
                m->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)p;
                m->EnableScnMdlCallbackTiming(1);
                q = *(unsigned int**)(p + 4);
                m->m_nodeIndex = (short)*q;
            }
            Matrix* mat = *(Matrix**)(self + 0x164);
            Vec3f pos;
            float z = mat->m[2][3];
            float y = mat->m[1][3];
            float x = mat->m[0][3];
            pos.m_y = y;
            pos.m_x = x;
            pos.m_z = z;
            Vec3f rot;
            mat->getRotate(&rot);
            float factor = lbl_46_rodata_140;
            float ax = rot.m_x;
            float ay = rot.m_y;
            float az = rot.m_z;
            float rx = factor * ax;
            float ry = factor * ay;
            float rz = factor * az;
            rot.m_x = rx;
            rot.m_y = ry;
            rot.m_z = rz;
            float* d = *(float**)(p + 4);
            d[2] = pos.m_x;
            d[3] = pos.m_y;
            d[4] = pos.m_z;
            nw4r::math::VEC3 v;
            LocalScale((const Vec*)(self + 0x158), (Vec*)&v, lbl_46_rodata_144);
            d = *(float**)(p + 4);
            d[8] = v.x;
            d[9] = v.y;
            d[10] = v.z;
            if (*(void**)((unsigned char*)m + 0xd4) == 0) {
                ((Class_1F30*)(self + 0x16c))->fn_46_6218(m);
                *(void**)((unsigned char*)m + 0xd4) = self + 0x16c;
            }
            ((Class_1F30*)(self + 0x16c))->fn_46_67E0(pos.m_x, pos.m_y, pos.m_z);
            ((Class_1F30*)(self + 0x16c))->fn_46_67F0(rot.m_x, rot.m_y, rot.m_z);
        }
    }
}
