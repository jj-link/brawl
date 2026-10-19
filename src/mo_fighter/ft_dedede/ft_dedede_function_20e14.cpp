#pragma force_active on
struct DededeSingletonStorage {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

extern "C" DededeSingletonStorage* fn_117_1EB30(void* self);

extern "C" void fn_117_20E14(unsigned char* self) {
    DededeSingletonStorage* storage = fn_117_1EB30(self + 0x1d10);
    storage->v6();
}
