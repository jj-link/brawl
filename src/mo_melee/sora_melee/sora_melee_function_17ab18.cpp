#include <types.h>
#pragma force_active on

extern "C" float lbl_27_rodata_2360;
extern "C" float lbl_27_rodata_2364;
extern "C" void fn_27_194B34(void* a, void* b);

class P70Obj {
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
    virtual void v15();
    virtual s32 v16();
};

struct Msg {
    s32 id;
    float a;
    float b;
    u8 pad[4];
};

class SubObj {
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30(Msg* msg, float f);
};

struct Holder {
    char pad[8];
    SubObj* sub;
    char pad2[0x64];
    P70Obj* p70;
};

struct Owner {
    char pad[0xd8];
    Holder* h;
};

extern "C" void fn_27_17AB18(void* unused, Owner* obj) {
    switch (obj->h->p70->v16()) {
    case 0x97: {
        Msg msg;
        msg.id = 0xfb;
        msg.a = lbl_27_rodata_2360;
        msg.b = lbl_27_rodata_2364;
        msg.pad[0] = 0;
        msg.pad[1] = 0;
        msg.pad[2] = 0;
        msg.pad[3] = 0;
        obj->h->sub->v30(&msg, lbl_27_rodata_2360);
        SubObj* sub = obj->h->sub;
        fn_27_194B34(obj, obj->h);
        sub->v7();
        break;
    }
    }
}
