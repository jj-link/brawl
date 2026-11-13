#include <types.h>
#pragma force_active on

extern "C" {
extern float lbl_6_rodata_60C;
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void printIndex__5MuMsgFUlUlPv(void*, u32, u32, void*);
}

struct Obj {
    char pad[0x10];
    void* model;
};

struct Self {
    char pad[0x40];
    Obj* a;
    char pad2[4];
    Obj* b[7];
};

extern "C" void fn_6_8BBC(Self* self, void* data, u32 a, u32 b) {
    int i;
    Obj* inner;
    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, a, b);
    *(void**)((char*)self + 0x74) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x100, 0xB);
    setMsgData__5MuMsgFPv(msg, data);

    inner = self->a;
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
        msg, 0, inner->model, 0, lbl_6_rodata_60C);
    printIndex__5MuMsgFUlUlPv(msg, 0, 0, 0);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
        msg, 1, inner->model, 1, lbl_6_rodata_60C);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
        msg, 2, inner->model, 2, lbl_6_rodata_60C);
    printIndex__5MuMsgFUlUlPv(msg, 2, 4, 0);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
        msg, 3, inner->model, 3, lbl_6_rodata_60C);
    printIndex__5MuMsgFUlUlPv(msg, 3, 5, 0);

    for (i = 0; i < 7; i++) {
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
            msg, i + 4, self->b[0]->model, 0, lbl_6_rodata_60C);
        self = (Self*)((char*)self + 4);
    }
}
