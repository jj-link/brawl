#pragma force_active on
struct Entry {
    unsigned int unused;
    void* value;
};

class Container {
public:
    virtual void unused();
    virtual Entry* at(int index);
};

class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual int valid();

    char padding[0x34];
    Container* entries;
};

extern "C" void* fn_27_28F528(void* value);

extern "C" void* fn_27_BAA38(Object* self, int index) {
    if (self->valid() == 0) {
        return 0;
    }
    return fn_27_28F528(self->entries->at(index)->value);
}
