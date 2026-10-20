#pragma force_active on
struct Result {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void invoke();
};

struct Interface {
    virtual void slot08();
    virtual void slot0C();
    virtual Result* get();
};

struct Inner {
    char padding[0x18];
    Interface* object;
};

struct Middle {
    char padding[0xD8];
    Inner* inner;
};

struct Object {
    char padding[0x60];
    Middle* middle;

    Middle* getMiddle() { return middle; }
};

extern "C" void fn_27_8CB54(Object* __restrict self) {
    self->getMiddle()->inner->object->get()->invoke();
}
