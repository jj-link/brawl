#pragma force_active on
struct Interface {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void invoke(void *);
};

extern "C" void fn_109_84C4(Interface *object, void **items, int count) {
    if (items == 0 || count <= 0) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        object->invoke(&items[i]);
    }
}
