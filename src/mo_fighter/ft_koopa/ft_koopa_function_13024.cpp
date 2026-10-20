#pragma force_active on
extern "C" {

struct Obj {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual int getStatus(void* param) = 0; // vtable +0x18
    virtual int setStatus(int value, void* param) = 0; // vtable +0x1c
};

struct Inner1 {
    char pad[0xd8];
    struct Inner0* inner0;
};

struct Inner0 {
    char pad[0x64];
    Obj* obj;
};

struct Param {
    char pad[0x60];
    Inner1* inner1;
};

void fn_102_13024(Param* param) {
    Obj* obj = param->inner1->inner0->obj;
    void* value = (void*)0x10000040;
    int status = obj->getStatus(value);
    if (status > 2) {
        obj->setStatus(2, value);
    }
}

}
