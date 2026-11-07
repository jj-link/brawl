#pragma force_active on

struct Vec3 { Vec3() {} float x, y, z; };

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_91BC0[];
extern char lbl_27_data_248[];
extern const float lbl_27_rodata_7B1C;

struct Inner { char pad[8]; float v; };
struct Res { char pad[0x34]; Inner* in; };
extern "C" Res* fn_27_3683E8(void*);

struct Base8 { int a, b; };
class Posture : public Base8 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual Vec3 getRot(int); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void setRot(int, Vec3*);
};
class Work {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual float get(unsigned int); virtual void set(float, unsigned int);
};
class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual int slot16();
};
struct Modules {
    char pad0[4]; Posture* posture;
    char pad8[0x5c]; Work* work;
    char pad68[8]; Object_vptr_0* m70;
};
struct Obj { char pad[8]; void* task; char padc[0xcc]; Modules* modules; };

extern "C" void fn_27_3686F8(void*, Obj* obj) {
    void* t = __dynamic_cast(obj->task, 0x3c, lbl_27_data_91BC0, lbl_27_data_248, 1);
    switch (obj->modules->m70->slot16()) {
    case 0:
        Vec3 v = obj->modules->posture->getRot(1);
        float f = obj->modules->work->get(0x21000000);
        f += fn_27_3683E8(t)->in->v;
        if (f > lbl_27_rodata_7B1C) f -= lbl_27_rodata_7B1C;
        v.x = f;
        obj->modules->posture->setRot(1, &v);
        obj->modules->work->set(f, 0x21000000);
        break;
    }
}
