#include <types.h>
#pragma force_active on

extern "C" {
void fn_18_11C4(void*);
extern char lbl_2_data_2630[];
extern float lbl_2_rodata_688;
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void setFontWidthModeAuto__5MuMsgFUl(void*, u32);
}

extern "C" void* fn_2_1A3F8(void* self, u32 unused1, u32 unused2, u32 value, void* data) {
    u8* s = reinterpret_cast<u8*>(self);
    fn_18_11C4(self);
    *reinterpret_cast<void**>(s + 0x668) = lbl_2_data_2630;
    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    *reinterpret_cast<void**>(s + 0x66c) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x100, 4);
    setMsgData__5MuMsgFPv(*reinterpret_cast<void**>(s + 0x66c), data);

    for (int i = 0; i < 4; ++i) {
        u8* a = *reinterpret_cast<u8**>(s + 0x64c);
        u8* b = *reinterpret_cast<u8**>(a + 0x170 + i * 4);
        void* c = *reinterpret_cast<void**>(b + 0x10);
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
            *reinterpret_cast<void**>(s + 0x66c), i, c, 0, lbl_2_rodata_688);
        setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(
            *reinterpret_cast<void**>(s + 0x66c), i, 1);
        setFontColor__5MuMsgFUlUcUcUcUc(
            *reinterpret_cast<void**>(s + 0x66c), i, 0x80, 0x80, 0x80, 0xff);
        setFontWidthModeAuto__5MuMsgFUl(
            *reinterpret_cast<void**>(s + 0x66c), i);
    }

    *reinterpret_cast<u32*>(s + 0x690) = value;
    return self;
}
