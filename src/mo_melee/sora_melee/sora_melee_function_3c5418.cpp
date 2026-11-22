#pragma force_active on
#include <types.h>

struct Vec2f { float x, y; };
struct Vec3 { float x, y, z; };
struct BaseE { char pad[8]; };
class ObjE : public BaseE {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual Vec2f s57(unsigned long, unsigned long);
};
extern "C" const float lbl_27_rodata_8080[];
extern "C" int fn_27_1922CC(void*, unsigned long);
extern "C" double atan2(double, double);
class ObjA {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual int s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9();
};
class ObjB {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual int s4(unsigned long); virtual void s5(int, unsigned long);
    virtual void s6(); virtual void s7(); virtual void s8(unsigned long); virtual void s9();
};
class ObjC {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual Vec3 s4(void*); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual float s9();
};
class ObjD {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5();
    virtual void s6(int, const Vec3&, Vec3*, int, int, float);
    virtual void s7(); virtual void s8(); virtual void s9();
};
inline Vec2f getVec(ObjE* obj) { return obj->s57(8, 0); }
inline void effect(u8* p, float fa, float r, const float* data) {
    Vec3 t;
    t.x = data[1];
    t.y = (data[2] == r) ? data[10] : data[9];
    t.z = fa;
    ObjD* d = *(ObjD**)(*(u8**)(p + 0xd8) + 0x88);
    d->s6(0xa, (*(ObjC**)(*(u8**)(p + 0xd8) + 0xc))->s4(*(u8**)(p + 0xd8)), &t, 0, -1, data[2]);
}
extern "C" void fn_27_3C5418(void* unused, u8* p) {
    const float* data = lbl_27_rodata_8080;
    if ((*(ObjA**)(*(u8**)(p + 0xd8) + 0x14))->s3() == 0) {
        (*(ObjB**)(*(u8**)(p + 0xd8) + 0x64))->s8(0x20000004);
        if ((*(ObjB**)(*(u8**)(p + 0xd8) + 0x64))->s4(0x20000004) <= 0) {
            ObjE* sub = *(ObjE**)(*(u8**)(p + 0xd8) + 0x10);
            Vec2f v = getVec(sub);
            float x = -v.x;
            float y = v.y;
            float fa = (float)atan2(x, y);
            float r = (*(ObjC**)(*(u8**)(p + 0xd8) + 0xc))->s9();
            effect(p, fa, r, data);
            ObjB* work = *(ObjB**)(*(u8**)(p + 0xd8) + 0x64);
            work->s5(fn_27_1922CC(p, 0x5dc2), 0x20000004);
        }
    }
}