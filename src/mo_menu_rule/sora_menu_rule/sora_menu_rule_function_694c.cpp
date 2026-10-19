#include <types.h>
#pragma force_active on

extern "C" {
void fn_18_11C4(void*);
extern char lbl_18_data_1748[];
extern float lbl_18_rodata_E0;
extern float lbl_18_rodata_E4;
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void setFontWidthModeAuto__5MuMsgFUl(void*, u32);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void FUN_800b9448__5MuMsgFUlb(void*, u32, bool);
void FUN_800b9460__5MuMsgFUlUcUcUcf(void*, u32, u8, u8, u8, float);
}

extern "C" void* fn_18_694C(void* self, u32 unused1, u32 unused2, void* data) {
    u8* s = reinterpret_cast<u8*>(self);
    fn_18_11C4(self);
    *reinterpret_cast<void**>(s + 0x668) = lbl_18_data_1748;
    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    *reinterpret_cast<void**>(s + 0x66c) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x100, 3);
    setMsgData__5MuMsgFPv(*reinterpret_cast<void**>(s + 0x66c), data);

    for (int i = 0; i < 3; i++) {
        u8* a = *reinterpret_cast<u8**>(s + 0x64c);
        u8* b = *reinterpret_cast<u8**>(a + 0x78);
        void* c = *reinterpret_cast<void**>(b + 0x10);
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(*reinterpret_cast<void**>(s + 0x66c), i, c, i, lbl_18_rodata_E0);
        setFontWidthModeAuto__5MuMsgFUl(*reinterpret_cast<void**>(s + 0x66c), i);
        setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(*reinterpret_cast<void**>(s + 0x66c), i, 1);
    }

    setFontColor__5MuMsgFUlUcUcUcUc(*reinterpret_cast<void**>(s + 0x66c), 0, 0xff, 0xff, 0xff, 0xff);
    FUN_800b9448__5MuMsgFUlb(*reinterpret_cast<void**>(s + 0x66c), 0, true);
    FUN_800b9460__5MuMsgFUlUcUcUcf(*reinterpret_cast<void**>(s + 0x66c), 0, 0x97, 0x1b, 0x21, lbl_18_rodata_E4);
    setFontColor__5MuMsgFUlUcUcUcUc(*reinterpret_cast<void**>(s + 0x66c), 1, 0xfb, 0xf9, 0xf9, 0xff);
    FUN_800b9448__5MuMsgFUlb(*reinterpret_cast<void**>(s + 0x66c), 1, false);
    setFontColor__5MuMsgFUlUcUcUcUc(*reinterpret_cast<void**>(s + 0x66c), 2, 0x97, 0x1b, 0x21, 0xff);
    FUN_800b9448__5MuMsgFUlb(*reinterpret_cast<void**>(s + 0x66c), 2, false);
    *(s + 0x688) = 1;
    return self;
}
