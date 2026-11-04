#pragma force_active on
extern "C" void fn_121_10CD0(void*, int);
extern "C" void fn_121_10BEC(void*, struct Vec3f*, struct Vec3f*);
extern const float lbl_121_rodata_64;
extern const float lbl_121_rodata_6C;

struct Vec3f { float x, y, z; };
struct Local { int a; int b; Vec3f p; Vec3f q; };

class Class_8C9C {
public:
    virtual void fn_121_22F8() = 0;
    virtual void fn_121_12B00() = 0;
    virtual void fn_121_14684() = 0;
    virtual void fn_121_14680() = 0;
    virtual void fn_121_1467C() = 0;
    virtual void fn_121_14678(int, int) = 0;
    virtual void fn_121_14670() = 0;
    virtual void fn_121_146B8() = 0;
    virtual void fn_121_146B0() = 0;
    virtual void fn_121_146A8() = 0;
    virtual void fn_121_146A0() = 0;
    virtual void fn_121_14698() = 0;
    virtual void fn_121_14630() = 0;
    virtual void fn_121_14664() = 0;
    virtual void fn_121_14658() = 0;
    virtual void fn_121_14650() = 0;
    virtual void fn_121_14644() = 0;
    virtual int fn_121_1463C(int) = 0;
};
class Class_8E20 {
public:
    virtual void fn_121_22F8() = 0;
    virtual void fn_121_12B5C() = 0;
    virtual void fn_121_14840() = 0;
    virtual void fn_121_14838() = 0;
    virtual void fn_121_14830() = 0;
    virtual void fn_121_14828() = 0;
    virtual void fn_121_14820() = 0;
    virtual void fn_121_14818() = 0;
    virtual void fn_121_14810() = 0;
    virtual void fn_121_14808() = 0;
    virtual void fn_121_14800() = 0;
    virtual int fn_121_147F8(unsigned int, int, Vec3f*, Vec3f*, float, int, int, int) = 0;
    virtual void fn_121_147F0() = 0;
    virtual void fn_121_147E8() = 0;
    virtual void fn_121_14798() = 0;
    virtual void fn_121_147E0() = 0;
    virtual void fn_121_147D0() = 0;
    virtual void fn_121_147C0() = 0;
};
struct Modules {
    char pad00[0x64];
    Class_8C9C* a;
    char pad68[0x20];
    Class_8E20* b;
};
extern "C" void fn_121_10AFC(void* arg0) {
    Modules* m = *reinterpret_cast<Modules**>(reinterpret_cast<char*>(arg0) + 0xd8);
    if (m->a->fn_121_1463C(0x22000014) != 0) {
        m = *reinterpret_cast<Modules**>(reinterpret_cast<char*>(arg0) + 0xd8);
        Class_8C9C* o30 = m->a;
        Class_8E20* o29 = m->b;
        fn_121_10CD0(arg0, 0x20000001);
        Local loc;
        fn_121_10BEC(arg0, &loc.p, &loc.q);
        loc.q.y = lbl_121_rodata_64;
        loc.a = -1;
        int r = o29->fn_121_147F8(0xE30004, 0, &loc.p, &loc.q, lbl_121_rodata_6C, 1, 0, 0);
        o30->fn_121_14678(r, 0x20000002);
    }
}