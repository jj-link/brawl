#include <mt/mt_matrix.h>
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

struct Class_21D0_base { char pad[0x168]; };
class Class_21D0_virtual {
public:
    virtual void fn_46_6810();
    virtual void fn_46_6890();
    virtual void fn_46_680C();
    virtual void fn_46_6808();
    virtual void fn_46_6804();
    virtual void fn_46_6800();
    virtual void fn_46_6850(nw4r::g3d::ScnMdlSimple*);
    virtual void fn_46_6D38(float, float, float);
    virtual void fn_46_6D48(float, float, float);
};
class Class_21D0 : public Class_21D0_base {
public:
    virtual void fn_46_6810();
    virtual void fn_46_6890();
    virtual void fn_46_680C();
    virtual void fn_46_6808();
    virtual void fn_46_6804();
    virtual void fn_46_6800();
    virtual void fn_46_6850(nw4r::g3d::ScnMdlSimple*);
    virtual void fn_46_6D38(float, float, float);
    virtual void fn_46_6D48(float, float, float);
};

extern const float lbl_46_rodata_150;
extern const float lbl_46_rodata_154;

extern "C" void fn_46_6B8C(unsigned char* self) {
    unsigned char* p = self + 0xd0;
    if (p != 0) {
        nw4r::g3d::ScnMdlSimple* m =
            **(nw4r::g3d::ScnMdlSimple***)(self + 0x44);
        if (m != 0 && *(Matrix**)(self + 0x164) != 0) {
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
            nw4r::math::VEC3 scaled;

            mat->getRotate(&rot);
            float factor = lbl_46_rodata_150;
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
            LocalScale((const Vec*)(self + 0x158), (Vec*)&scaled,
                lbl_46_rodata_154);
            d = *(float**)(p + 4);
            d[8] = scaled.x;
            d[9] = scaled.y;
            d[10] = scaled.z;
            if (*(void**)((unsigned char*)m + 0xd4) == 0) {
                ((Class_21D0_virtual*)(self + 0x168))->fn_46_6850(m);
                *(void**)((unsigned char*)m + 0xd4) = self + 0x168;
            }
            ((Class_21D0_virtual*)(self + 0x168))->fn_46_6D38(pos.m_x, pos.m_y, pos.m_z);
            ((Class_21D0_virtual*)(self + 0x168))->fn_46_6D48(rot.m_x, rot.m_y, rot.m_z);
        }
    }
}
