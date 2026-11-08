#pragma force_active on
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};
struct Bits { int x, y, z; };
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3 slot4();
    virtual void slot5(const Vec3&);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(float, unsigned int);
};
struct Modules {
    char pad[12];
    Object_vptr_0* posture;
    char pad2[0x54];
    Object_vptr_0* work;
};
struct Accessor {
    char pad[0xd8];
    Modules* modules;
};
extern const float lbl_96_rodata_A8;
extern const float lbl_96_rodata_BC;
extern "C" void fn_96_1BCD8(float*, float, int, const float*, const float*);
extern "C" void fn_96_19528(int arg0, Accessor* arg1, const Vec3* arg2, float f) {
    if (arg1->modules->work->slot12(0x21000005) < f) {
        arg1->modules->work->slot15(lbl_96_rodata_BC, 0x21000005);
    }
    Vec3 a = arg1->modules->posture->slot4();
    Bits b = *(const Bits*)arg2;
    *(float*)&b.z = lbl_96_rodata_A8;
    a.z = lbl_96_rodata_A8;
    Vec3 out;
    fn_96_1BCD8(&out.x, arg1->modules->work->slot12(0x21000005) / f, arg0, &a.x, (float*)&b.x);
    arg1->modules->posture->slot5(out);
}