#pragma force_active on
struct Vec2 {
    Vec2() {}
    Vec2(const Vec2& v) : x(v.x), y(v.y) {}
    float x, y;
};
struct Base { int a, b; };
class Ground : public Base {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual int s34(int);
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38();
    virtual Vec2 s39(int); virtual float s40(int);
};
class soPostureModuleImpl {
public:
    virtual void isNull(); virtual ~soPostureModuleImpl();
    virtual void fn_27_2362C(); virtual void fn_27_236B0(); virtual void fn_27_25088();
    virtual void fn_27_23E84(); virtual void fn_27_25184(); virtual void fn_27_2370C();
    virtual void fn_27_23728(); virtual void fn_27_23E28(); virtual void fn_27_23CC0(float);
    virtual void fn_27_25068(); virtual void fn_27_23A9C(); virtual void fn_27_23B18();
    virtual void fn_27_250FC(); virtual void fn_27_250A4(); virtual void fn_27_23BF8();
    virtual void fn_27_251B8(); virtual void fn_27_251B0(); virtual void fn_27_23C14();
};
class Work {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void setValue(unsigned int, float);
};
struct Modules {
    char pad[0xc]; soPostureModuleImpl* posture; Ground* ground;
    char pad2[0x50]; Work* work;
};
struct Object { char pad[0xd8]; Modules* modules; };
extern "C" void fn_27_18AA38(void*, Object* obj) {
    if (obj->modules->ground->s34(0)) {
        float f = obj->modules->ground->s40(0);
        Vec2 v = obj->modules->ground->s39(0);
        v.x -= f;
        obj->modules->posture->fn_27_23CC0(f);
        obj->modules->posture->fn_27_23C14();
        obj->modules->work->setValue(0x21000005, v.x);
        obj->modules->work->setValue(0x21000006, v.y);
    }
}