#pragma force_active on
struct VBase {
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
    virtual void f13(void* arg);
};

extern "C" {
void fn_2_16F28(char* self) {
    VBase* obj = *(VBase**)(self + 0x654);
    obj->f13(*(void**)(*(char**)(*(char**)(self + 0x64c) + 0x9c) + 0x10));

    obj = *(VBase**)(self + 0x654);
    obj->f13(*(void**)(*(char**)(*(char**)(self + 0x64c) + 0xa0) + 0x10));
}
}
