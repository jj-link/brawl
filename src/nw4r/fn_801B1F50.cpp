#pragma force_active on
#include <types.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int, void*, int, int*);
};

struct Obj {
    unsigned char pad0[0xD4];
    Object_vptr_0* unkD4;
    unsigned char unkD8;
    unsigned short unkDA;
    unsigned char pad1[0xE8 - 0xDC];
    int unkE8;
    unsigned char pad2[0x110 - 0xEC];
    int unk110;
    int unk114;
    int unk118;
    unsigned char pad3[0x144 - 0x11C];
};

extern "C" s32 fn_801AFB44(void*);
extern "C" void* fn_801AFB10(void*);
extern "C" void* fn_801AFAEC(void*);
extern "C" void fn_801A64B0(void*, void*, void*, void*, int, int, void*, int);

extern "C" void fn_801B1F50(Obj* arg0, int arg1, int* arg2) {
    int sp8;
    if (arg0->unkD4 != NULL && (arg0->unkDA & 0x10) && (arg0->unkD8 & 1)) {
        arg0->unkD4->slot4(1, arg0, arg1, arg2);
    }
    int var_r29 = arg2 != NULL ? *arg2 : arg0->unk118;
    int r28 = arg0->unk110;
    sp8 = arg0->unkE8;
    fn_801A64B0(&sp8, fn_801AFAEC(arg0), fn_801AFB10(arg0), (void*)fn_801AFB44(arg0), r28, 0, (char*)arg0 + 0x144, var_r29);
    if (arg0->unkD4 != NULL && (arg0->unkDA & 0x10) && (arg0->unkD8 & 4)) {
        arg0->unkD4->slot4(4, arg0, arg1, arg2);
    }
}
