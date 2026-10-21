#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Prefix {
    void* base;
    u8 flag;
    u8 pad[3];
};

struct Work : Prefix {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void reset();

    void* owner;
    u32 count;
    void* data;
    u32 count2;
    void* data2;
    u32 count3;
};

struct Object {
    u8 pad[0x1c8];
    Work work;
};

extern "C" void* __vt__19soGeneralWorkSimple[];

extern "C" Object* fn_27_37C8BC(Object* obj) {
    Work* work = &obj->work;
    work->flag = 0;
    work->owner = obj;
    *(void***)((u8*)work + 8) = __vt__19soGeneralWorkSimple;
    work->base = __vt__19soGeneralWorkSimple + 2;
    work->count = 0x4c;
    work->data = (u8*)obj + 0x130;
    work->count2 = 0x23;
    work->data2 = (u8*)obj + 0x1bc;
    work->count3 = 3;
    work->reset();
    return obj;
}
