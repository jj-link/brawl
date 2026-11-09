#pragma force_active on
#include <types.h>
#include <mu/mu_msg.h>

extern "C" {
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, f32);
void fn_800B9488(void*, u32, u32);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void fn_800B9428(void*, u32, f32);
extern f32 lbl_10_rodata_56C;
extern f32 lbl_10_rodata_570;
}

extern "C" void fn_10_114FC(void* self, void* data) {
    void* msg;
    char* s = (char*)self;
    int i;
    u32 idx;
    char* p;

    msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(3, 0x2a, 0x2b);
    *(void**)(s + 0x40c) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x100, 0x1f);
    setMsgData__5MuMsgFPv(msg, data);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0, *(void**)((char*)*(void**)(s + 0xd0) + 0x10), 0, lbl_10_rodata_56C);
    fn_800B9488(msg, 0, 1);

    p = s;
    for (i = 0; i < 9; i++) {
        idx = i + 1;
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, idx, *(void**)((char*)*(void**)(p + 0xf0) + 0x10), 0, lbl_10_rodata_56C);
        fn_800B9488(msg, idx, 1);
        p += 4;
    }

    p = s;
    for (i = 0; i < 9; i++) {
        idx = i + 10;
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, idx, *(void**)((char*)*(void**)(p + 0xf0) + 0x10), 1, lbl_10_rodata_56C);
        fn_800B9488(msg, idx, 1);
        p += 4;
    }

    p = s;
    for (i = 0; i < 9; i++) {
        idx = i + 0x13;
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, idx, *(void**)((char*)*(void**)(p + 0xf0) + 0x10), 2, lbl_10_rodata_56C);
        fn_800B9488(msg, idx, 1);
        p += 4;
    }

    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0x1c, *(void**)((char*)*(void**)(s + 0x11c) + 0x10), 0, lbl_10_rodata_56C);
    fn_800B9488(msg, 0x1c, 1);
    setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(msg, 0x1c, 1);
    fn_800B9428(msg, 0x1c, lbl_10_rodata_570);

    s = *(char**)(s + 0x144);
    if (s != NULL) {
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0x1d, *(void**)(s + 0x10), 0, lbl_10_rodata_56C);
        fn_800B9488(msg, 0x1d, 1);
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0x1e, *(void**)(s + 0x10), 1, lbl_10_rodata_56C);
        fn_800B9488(msg, 0x1e, 1);
    }
}
