#include <types.h>
#pragma force_active on

extern "C" {
void fn_18_11C4(void*);
extern char lbl_2_data_39A0[];
extern float lbl_2_rodata_F30;
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void setFontWidthModeAuto__5MuMsgFUl(void*, u32);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void FUN_800b9448__5MuMsgFUlb(void*, u32, bool);
}

extern "C" void* fn_2_2CEC0(void* self, u32 unused1, u32 unused2, void* data) {
    u8* s = reinterpret_cast<u8*>(self);
    fn_18_11C4(self);
    *reinterpret_cast<void**>(s + 0x668) = lbl_2_data_39A0;
    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    *reinterpret_cast<void**>(s + 0x66c) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x400, 2);
    setMsgData__5MuMsgFPv(*reinterpret_cast<void**>(s + 0x66c), data);

    for (int i = 0; i < 2; i++) {
        setFontWidthModeAuto__5MuMsgFUl(*reinterpret_cast<void**>(s + 0x66c), i);
        u8* a = *reinterpret_cast<u8**>(s + 0x64c);
        u8* b = *reinterpret_cast<u8**>(a + 0x30c);
        void* c = *reinterpret_cast<void**>(b + 0x10);
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(*reinterpret_cast<void**>(s + 0x66c), i, c, i, lbl_2_rodata_F30);
        setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(*reinterpret_cast<void**>(s + 0x66c), i, 0);
        FUN_800b9448__5MuMsgFUlb(*reinterpret_cast<void**>(s + 0x66c), i, false);
    }

    setFontColor__5MuMsgFUlUcUcUcUc(*reinterpret_cast<void**>(s + 0x66c), 0, 0, 0, 0, 0xff);
    setFontColor__5MuMsgFUlUcUcUcUc(*reinterpret_cast<void**>(s + 0x66c), 1, 0xfa, 0xfa, 0xfa, 0xff);
    return self;
}