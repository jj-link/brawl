#pragma force_active on
extern "C" void fn_801B4CB0(void*, void*, int);

struct Obj {
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
    virtual void v13(void*, void*);
};

extern "C" {
void fn_16_3B94(char* self) {
    if (*(void**)(self + 0x3f8) != 0) {
        char* p = *(char**)(self + 0x4c);
        fn_801B4CB0(*(void**)(self + 0x3f8), *(void**)(p + 0x10), *(int*)(self + 0x3fc));
    } else {
        void** q = *(void***)(self + 0x4c);
        Obj* obj = *(Obj**)(self + 0xa8);
        obj->v13(*(void**)((char*)obj + 0xe4), q[4]);
    }
    *(int*)(self + 0x468) = 30;
}
}
