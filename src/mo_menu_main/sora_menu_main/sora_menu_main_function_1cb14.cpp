#pragma force_active on
extern "C" void fn_800B8A0C(void*, int);
extern "C" void fn_800B8EDC(void*, void*);
extern "C" void free__13gfHeapManagerFPv(void*);

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
    virtual void v11();
    virtual void v12();
    virtual void call(void*);
};

extern "C" void fn_2_1CB14(char* self) {
    Obj* o = *(Obj**)(self + 0x654);
    void* p = *(void**)(*(char**)(self + 0x64C) + 0x1BC);
    o->call(*(void**)((char*)p + 0x10));
    o = *(Obj**)(self + 0x654);
    void* q = *(void**)(self + 0x650);
    o->call(*(void**)((char*)q + 0x24));

    void* mem = *(void**)(self + 0x678);
    if (mem) {
        free__13gfHeapManagerFPv(mem);
        *(void**)(self + 0x678) = 0;
    }
    *(void**)(self + 0x67C) = 0;

    int i = 0;
    int off = 0;
    do {
        char* base = *(char**)(self + 0x64C);
        fn_800B8EDC(*(void**)(self + 0x688), *(void**)(base + 0x1C4 + off));
        i++;
        off += 4;
    } while (i < 4);
    if (*(void**)(self + 0x688)) {
        fn_800B8A0C(*(void**)(self + 0x688), 1);
        *(void**)(self + 0x688) = 0;
    }
}