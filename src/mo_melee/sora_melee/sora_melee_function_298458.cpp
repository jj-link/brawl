#include <math.h>
#include <so/so_module_accesser.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
#pragma fp_contract off

#define ACCESSER(obj) (*reinterpret_cast<soModuleAccesser**>(static_cast<unsigned char*>(obj) + 0x60))

struct SingletonBss {
    char pad0[0x44];
    float f44;
    unsigned char b48;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
float getParamFloat__8BaseItemFUl(void*, unsigned long);
double __fabs(double);
extern void* lbl_27_bss_F0;
extern const float lbl_27_rodata_46C8[];
}

extern "C" int fn_27_298458(void* unused, void* item) {
    float f30;
    const float* k = lbl_27_rodata_46C8;
    soWorkManageModule& work = ACCESSER(item)->getWorkManageModule();
    float v0 = work.getFloat(0x11000000);
    if ((float)__fabs((double)v0) <= k[5]) {
        return 1;
    }
    float v1 = work.getFloat(0x11000001);

    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (p != 0) p = fn_27_5BCD0(p);
        lbl_27_bss_F0 = p;
    }
    if (static_cast<SingletonBss*>(lbl_27_bss_F0)->b48 != 0) {
        if (lbl_27_bss_F0 == 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
            if (p != 0) p = fn_27_5BCD0(p);
            lbl_27_bss_F0 = p;
        }
        f30 = static_cast<SingletonBss*>(lbl_27_bss_F0)->f44;
    } else {
        f30 = k[0];
    }
    float f28a = f30 * getParamFloat__8BaseItemFUl(item, 0x2938);
    float dy = f30 * getParamFloat__8BaseItemFUl(item, 0x2939);
    if (v1 > k[5] && v0 > k[5]) {
        v0 += dy;
    } else if (v1 <= k[5] && v0 <= k[5]) {
        v0 -= dy;
    } else if (v1 > k[5] && v0 <= k[5]) {
        v0 -= f28a;
    } else if (v1 <= k[5] && v0 > k[5]) {
        v0 += f28a;
    }

    float f28;
    float p3a = getParamFloat__8BaseItemFUl(item, 0x293A);
    float p3b = getParamFloat__8BaseItemFUl(item, 0x293B);
    if ((float)__fabs((double)v1) < p3b && (float)__fabs((double)v0) < p3b) {
        f28 = k[5];
        v0 = f28;
    } else {
        f28 = v1 + v0 * f30;
    }

    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (p != 0) p = fn_27_5BCD0(p);
        lbl_27_bss_F0 = p;
    }
    if (fn_27_5BEA8(lbl_27_bss_F0) != 0) {
        if (f28 > p3a) {
            f28 = p3a;
            v0 *= k[10];
        } else if (f28 < -p3a) {
            f28 = -p3a;
            v0 *= k[10];
        }
    }

    work.setFloat(v0, 0x11000000);
    work.setFloat(f28, 0x11000001);

    float g = ACCESSER(item)->getCollisionAttackModule().getPowerMul();
    float c = g - f30 * getParamFloat__8BaseItemFUl(item, 0x293D);
    if (c < k[5]) {
        c = k[5];
    }
    ACCESSER(item)->getCollisionAttackModule().setPowerMul(c);

    Vec3f vec;
    vec.m_z = f28;
    vec.m_x = k[5];
    vec.m_y = k[5];
    ACCESSER(item)->getModelModule().setNodeRotate(4, &vec);
    return 1;
}
