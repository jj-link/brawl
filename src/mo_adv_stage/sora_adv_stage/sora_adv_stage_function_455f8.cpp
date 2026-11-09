#include <types.h>
#pragma force_active on

extern "C" {
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void fn_800B8A0C(void*, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(void*, u32, u32);
extern float lbl_40_rodata_B04;
extern float lbl_40_rodata_B08;
}

extern "C" void fn_40_455F8(u8* self) {
    void* msg;
    u8* rowBase;
    int line;
    u32 row;
    int col;
    int align;
    float scale;

    msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(
        1, *(u32*)(self + 0x1ac), *(u32*)(self + 0x1b0));
    if (*(void**)(self + 0x1888) != msg) {
        fn_800B8A0C(*(void**)(self + 0x1888), 1);
        *(void**)(self + 0x1888) = msg;
    }
    allocMsgBuf__5MuMsgFUlUl(*(void**)(self + 0x1888), 0x100, 0x18);
    setMsgData__5MuMsgFPv(
        *(void**)(self + 0x1888),
        getBuffer__14gfFileIOHandleCFv(self + 0x1528));

    rowBase = self;
    line = 0;
    row = 0;
    do {
        col = 0;
        do {
            scale = col <= 3 ? lbl_40_rodata_B04 : lbl_40_rodata_B08;
            attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(
                *(void**)(self + 0x1888), line,
                *(void**)(*(u8**)(rowBase + 0x1580) + 0x10), col, scale);

            switch (col) {
            case 0:
            case 1:
            case 2:
            case 3:
                align = 0;
                break;
            case 4:
            case 5:
                align = 1;
                break;
            }

            setAlignMode__5MuMsgFUlQ25MuMsg9AlignMode(
                *(void**)(self + 0x1888), line, align);

            ++col;
            ++line;
        } while (col < 6);
        ++row;
        rowBase += 0xc0;
    } while (row < 4);
}
