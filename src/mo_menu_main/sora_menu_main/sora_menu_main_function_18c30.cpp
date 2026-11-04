#include <types.h>
#pragma force_active on

extern "C" {
void fn_18_11C4(void*);
extern char lbl_2_data_23C0[];
extern float lbl_2_rodata_660;
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void fn_800B9488(void*, u32, u32);
}

extern "C" void* fn_2_18C30(void* self) {
    u8* s = reinterpret_cast<u8*>(self);
    fn_18_11C4(self);
    *reinterpret_cast<void**>(s + 0x668) = lbl_2_data_23C0;
    void* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(2, 0x2a, 0x2b);
    *reinterpret_cast<void**>(s + 0x694) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x100, 5);

    for (int i = 0; i < 5; i++) {
        u8* a = *reinterpret_cast<u8**>(s + 0x64c);
        u8* b = *reinterpret_cast<u8**>(a + 0x110 + i * 4);
        void* c = *reinterpret_cast<void**>(b + 0x10);
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
            *reinterpret_cast<void**>(s + 0x694), i, c, 0, lbl_2_rodata_660);
        setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(
            *reinterpret_cast<void**>(s + 0x694), i, 0);
        setFontColor__5MuMsgFUlUcUcUcUc(
            *reinterpret_cast<void**>(s + 0x694), i, 0x14, 0x14, 0x50, 0xff);
        fn_800B9488(
            *reinterpret_cast<void**>(s + 0x694), i, 1);
    }
    return self;
}