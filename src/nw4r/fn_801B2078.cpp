#pragma force_active on

#include <types.h>

class Callee {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void call(int, void*, int, int*);
};

struct Obj {
    unsigned char pad0[0xD4];
    Callee* unkD4;
    unsigned char unkD8;
    unsigned short unkDA;
    unsigned char pad1[0xE8 - 0xDC];
    int unkE8;
    unsigned char pad2[0x114 - 0xEC];
    int unk114;
    int unk118;
    unsigned char pad3[0x144 - 0x11C];
};

extern "C" s32 fn_801AFB44(void* p);
extern "C" void* fn_801AFB10(void* p);
extern "C" void* fn_801AFAEC(void* p);
extern "C" void fn_801A64B0(void* a, void* b, void* c, void* d, int e, int f, void* g, int h);

extern "C" void fn_801B2078(Obj* arg0, int arg1, int* arg2) {
    int sp8;
    if (arg0->unkD4 != NULL && (arg0->unkDA & 0x20) && (arg0->unkD8 & 1)) {
        arg0->unkD4->call(1, arg0, arg1, arg2);
    }
    int var_r29 = arg2 != NULL ? *arg2 : arg0->unk118;
    int r28 = arg0->unk114;
    sp8 = arg0->unkE8;
    fn_801A64B0(&sp8, fn_801AFAEC(arg0), fn_801AFB10(arg0), (void*)fn_801AFB44(arg0), 0, r28, (char*)arg0 + 0x144, var_r29);
    if (arg0->unkD4 != NULL && (arg0->unkDA & 0x20) && (arg0->unkD8 & 4)) {
        arg0->unkD4->call(4, arg0, arg1, arg2);
    }
}
