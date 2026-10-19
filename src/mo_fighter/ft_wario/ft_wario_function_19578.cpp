#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Arg {
    u32 id;
    u8 flag;
};

class Obj {
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
    virtual void v14();
    virtual void v15(s32, void*);
    virtual void v16();
    virtual void v17();
};

extern "C" {
void fn_110_19578(void* unused, u8* self);
}

extern "C" void fn_110_19578(void* unused, u8* self) {
    Arg arg;
    Obj* obj = *(Obj**)(*(u8**)(self + 0xd8) + 0x54);
    arg.id = 0x83e;
    arg.flag = 0;
    obj->v15(3, &arg);
}
