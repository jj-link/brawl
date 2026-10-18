#pragma force_active on
struct Subobject {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct Object {
    char pad[0xC];
    Subobject subobject;
};

extern "C" int fn_27_C3960(void*);
extern "C" int fn_27_C3974(void*, int);
extern "C" void fn_96_1D68C(void*, int);

extern "C" void fn_96_1D734(Object* object) {
    object->subobject.f6();
    int count = fn_27_C3960(&object->subobject);
    for (int index = 0; index < count; ++index) {
        int value = fn_27_C3974(&object->subobject, index);
        if (value > -1) {
            fn_96_1D68C(object, value);
        }
    }
}
