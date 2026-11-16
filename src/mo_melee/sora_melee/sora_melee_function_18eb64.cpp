#pragma force_active on
struct Vec2 {
    Vec2(const Vec2& o) : x(o.x), y(o.y) {}
    float x, y, z;
};
struct Vec3 {
    Vec3() {}
    float x, y, z;
};
class PostureImpl {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual Vec3 getPos();
    virtual void setPos(const Vec3*);
};
class Work {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual float getValue(unsigned int);
    virtual void setValue(unsigned int, float);
};
class Param {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual Vec2 getPos(int, int, int);
};
struct Modules {
    char pad0[0xC]; PostureImpl* posture;
    char pad1[0x54 - 0x10]; Param* param;
    char pad2[0x64 - 0x58]; Work* work;
};
struct Object { char pad[0xD8]; Modules* modules; };
extern "C" void fn_27_18EB64(void*, Object* obj) {
    Vec2 p = obj->modules->param->getPos(4, 0, 0);
    float cur4 = obj->modules->work->getValue(0x21000004);
    float cur5 = obj->modules->work->getValue(0x21000005);
    Vec3 local = obj->modules->posture->getPos();
    local.x += p.x - cur4;
    local.y += p.y - cur5;
    obj->modules->posture->setPos(&local);
    obj->modules->work->setValue(0x21000004, p.x);
    obj->modules->work->setValue(0x21000005, p.y);
}