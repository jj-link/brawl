#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(int);
};
extern "C" void fn_119_8F00(float*, float, float, float);
extern "C" void fn_119_8E54(float* result, unsigned char* owner) {
    Object_vptr_0* work = *(Object_vptr_0**)(*(unsigned char**)(owner + 0xD8) + 0x64);
    float x, y, z;
    z = work->slot12(0x2100000E);
    y = work->slot12(0x2100000D);
    x = work->slot12(0x2100000C);
    fn_119_8F00(result, x, y, z);
}