#pragma force_active on

struct Inner {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(void* obj);
};

struct Work {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int id);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(unsigned int id);
};

struct Modules {
    char padding[0x64];
    Work* work;
};

struct Object {
    char padding[0xD8];
    Modules* modules;
};

struct Self {
    char padding[4];
    Inner* inner;
};

extern "C" void fn_27_16A6E4(Self* self, Object* object) {
    self->inner->slot2();
    self->inner->slot4(object);
    if (object->modules->work->slot4(0x20000001) > 0) {
        object->modules->work->slot8(0x20000001);
    }
}
