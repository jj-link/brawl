#pragma force_active on
struct Object {
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
    virtual void* f4();
    virtual void* f5();
    virtual void* f6();
    virtual void* f7();
    virtual void* f8();
    virtual void* f9();
    virtual void* f10();
    virtual void* f11();
    virtual void* f12();
    virtual void* f13();
    virtual void* f14();
    virtual void* f15();
    virtual void* get();
};

struct Inner {
    char pad[0x70];
    Object* object;
};

struct Fighter {
    char pad[0xD8];
    Inner* inner;
};

extern "C" void fn_27_613AC(Fighter*, void*);

extern "C" void fn_115_1B810(void*, Fighter* fighter) {
    Object* object = fighter->inner->object;
    void* value = object->get();
    fn_27_613AC(fighter, value);
}
