#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" void* fn_8009D2DC();
extern "C" double fn_80400AB8(double);
extern "C" float lbl_805A1F90, lbl_805A1FA0, lbl_805A2008;

inline Vec2f getVec() {
    Vec3f* p = (Vec3f*)fn_8009D2DC();
    return Vec2f(p->m_x * p->m_z, p->m_y * p->m_z);
}

inline float half(float x) { return lbl_805A1FA0 * x; }

extern "C" void fn_800A5E50(void* arg) {
    float f31 = *(float*)((char*)arg + 0xdc);
    float f30;
    float x;
    float y;
    const Vec2f& v = getVec();
    char* obj = *(char**)arg;
    Vec2f w;
    Vec2f::copy(w, v);
    y = w.m_y;
    x = w.m_x;
    f30 = *(float*)(obj + 0xe4);
    float f4 = f31 * (float)fn_80400AB8(half(*(float*)(obj + 0xd0)));

    float factor = lbl_805A2008;
    float dx = lbl_805A1FA0 * *(float*)(obj + 0x11c);
    float dy = lbl_805A1FA0 * *(float*)(obj + 0x120);
    Vec3f result;
    result.m_x = factor * (x * (f30 * (f4 / dx)));
    result.m_y = factor * (y * (f4 / dy));
    result.m_z = lbl_805A1F90;
    *(Vec3f*)(obj + 0x9c) = result;
}
