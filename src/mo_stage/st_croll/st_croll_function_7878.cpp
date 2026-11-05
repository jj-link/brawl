#include <types.h>
#pragma force_active on

struct Obj {
    char pad[0xA0];
    virtual void exit(int);
};

struct Context {
    Obj* obj;
    int unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __ct__7MessageFUlQ25Heaps8HeapType(void*, unsigned long, int);
extern "C" void fn_8006EE5C(void*, int);
extern "C" void changeMsgBuf__7MessageFi(void*, int);
extern "C" void clearMsgBuf__7MessageFv(void*);
extern "C" void setFixedWidth__7MessageFf(void*, float);
extern "C" void setCallProjection__7MessageFUc(void*, unsigned char);
extern "C" const float lbl_90_rodata_0;
extern "C" const float lbl_90_rodata_40;

extern "C" void fn_90_7878(Context* self) {
    if (self->obj) {
        if (self->obj) {
            if (self->obj) {
                self->obj->exit(1);
            }
            self->obj = 0;
        }
    }
    void* msg = __nw__FUlQ25Heaps8HeapType(0x1E0, 0xF);
    if (msg) {
        msg = __ct__7MessageFUlQ25Heaps8HeapType(msg, 0x400, 0xF);
    }
    self->obj = (Obj*)msg;
    fn_8006EE5C(self->obj, 1);
    changeMsgBuf__7MessageFi(self->obj, -1);
    clearMsgBuf__7MessageFv(self->obj);
    setFixedWidth__7MessageFf(self->obj, lbl_90_rodata_40);
    setCallProjection__7MessageFUc(self->obj, 0);
    self->unk4 = 0;
    self->unk8 = lbl_90_rodata_0;
    self->unkC = lbl_90_rodata_0;
    self->unk10 = lbl_90_rodata_0;
    self->unk14 = lbl_90_rodata_0;
}
