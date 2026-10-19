#include <types.h>
#pragma force_active on

extern "C" {
void fn_18_11C4(void*);
extern char lbl_2_data_22D8[];
extern float lbl_2_rodata_638;
extern float lbl_2_rodata_63C;
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void setFontWidthModeAuto__5MuMsgFUl(void*, u32);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void getWScale__5MuMsgFUlf(void*, u32, float);
}

extern "C" void* fn_2_17E48(void* self, u32 unused1, u32 unused2, void* data) {
    u8* s = reinterpret_cast<u8*>(self);
    fn_18_11C4(self);
    *reinterpret_cast<void**>(s + 0x668) = lbl_2_data_22D8;
    *(s + 0x670) = 0;
    *reinterpret_cast<u16*>(s + 0x640) = 5;
    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    *reinterpret_cast<void**>(s + 0x66c) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x100, 3);
    setMsgData__5MuMsgFPv(*reinterpret_cast<void**>(s + 0x66c), data);

    for (int i = 0; i < 3; i++) {
        u8* a = *reinterpret_cast<u8**>(s + 0x64c);
        u8* b = *reinterpret_cast<u8**>(a + 0x1a0);
        void* c = *reinterpret_cast<void**>(b + 0x10);
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(*reinterpret_cast<void**>(s + 0x66c), i, c, i, lbl_2_rodata_638);
        setFontWidthModeAuto__5MuMsgFUl(*reinterpret_cast<void**>(s + 0x66c), i);
        setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(*reinterpret_cast<void**>(s + 0x66c), i, 0);
        getWScale__5MuMsgFUlf(*reinterpret_cast<void**>(s + 0x66c), i, lbl_2_rodata_63C);
    }
    return self;
}
