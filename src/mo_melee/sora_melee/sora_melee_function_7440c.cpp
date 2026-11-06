#pragma force_active on
class soNullable {
public:
    virtual void isNull();
    virtual void** fn_27_73C90(int index);
    virtual void fn_27_73D24();
    virtual int fn_27_74B94();
    virtual void fn_27_75684();
    virtual void fn_27_758E4();
    virtual void fn_27_73DA4();
    virtual void fn_27_73E50();
    virtual void fn_27_73EFC();
    virtual void fn_27_73FA8();
    virtual void fn_27_74054();
    virtual void fn_27_74100();
    virtual void fn_27_741AC();
};

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
    virtual void slot12(int, int, int);
};

struct SelfObj {
    char pad[0x30];
    soNullable* container;
    int index;
};

extern "C" void fn_27_7440C(SelfObj* self, int a, int b, int c) {
    int idx = self->index;
    if (idx >= 0) {
        if (idx < self->container->fn_27_74B94()) {
            void** slot = self->container->fn_27_73C90(idx);
            Object_vptr_0* obj = (Object_vptr_0*)*slot;
            if (obj != 0) {
                obj->slot12(a, b, c);
            }
        }
    }
}
