#pragma force_active on

#include <types.h>

extern "C" void fn_27_178AB8(s32 unused, void* p);
extern "C" void* getData__20ftCommonDataAccesserCF6ftKind(const void* this_, int kind);
extern "C" const float lbl_95_rodata_60;

extern char g_ftCommonDataAccesser;

struct Msg {
    int a;
    float b;
    float c;
    char d;
    char e;
    char f;
    char g;
};

class ObjA {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void f7();
};

class ObjB {
public:
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
    virtual float f14();
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
    virtual void v30();
    virtual void v31();
    virtual void f32(Msg*);
};

class ObjC {
public:
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual int f34(int);
};

struct Mid {
    u8 pad0[0x8];
    ObjB* p8;
    u8 pad1[0x70 - 0xC];
    ObjC* p70;
    u8 pad2[0xA0 - 0x74];
    ObjA* pA0;
};

struct Outer {
    u8 pad[0xd8];
    Mid* mid;
};

struct Range {
    float min;
    float max;
    float* arr;
};

struct ParamThing {
    u8 pad[0xa4];
    Range* a;
    Range* b;
    Range* c;
};

extern "C" void fn_95_FB5C(s32 arg0, Outer* arg1) {
    fn_27_178AB8(arg0, arg1);
    ParamThing* param = (ParamThing*)getData__20ftCommonDataAccesserCF6ftKind(&g_ftCommonDataAccesser, 4);
    int kind = arg1->mid->p70->f34(0);
    Range* range;
    int id;
    switch (kind) {
    case 0x34:
        range = param->a;
        id = 0x6c;
        break;
    case 0x36:
        range = param->b;
        id = 0x6d;
        break;
    case 0x38:
        range = param->c;
        id = 0x6e;
        break;
    default:
        return;
    }
    float f = arg1->mid->p8->f14();
    if (f >= range->min && f <= range->max) {
        int idx = (int)(f - range->min);
        float* arr = range->arr;
        f = arr[idx];
    }
    Msg m;
    m.a = id;
    m.b = f;
    m.c = lbl_95_rodata_60;
    m.d = 0;
    m.e = 0;
    m.f = 1;
    m.g = 0;
    arg1->mid->p8->f32(&m);
    arg1->mid->pA0->f7();
}
