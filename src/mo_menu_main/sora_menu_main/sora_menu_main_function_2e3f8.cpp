#pragma force_active on
typedef unsigned int u32;

struct VObj {
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
    virtual void call(void* arg);
};

extern "C" void fn_2_2E3F8(char* self) {
    for (u32 i = 0; i < 4; i++) {
        VObj* obj = *(VObj**)(self + 0x654);
        char* e = *(char**)(*(char**)(self + 0x64c) + i * 4 + 0x32c);
        obj->call(*(void**)(e + 0x10));
    }
}
