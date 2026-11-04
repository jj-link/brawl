#include <types.h>
#pragma force_active on

extern "C" {
extern float lbl_805A27BC;
extern float lbl_805A27C0;
extern float lbl_805A27C4;

struct MsgCfg {
    unsigned char data[0x27];
};
extern MsgCfg lbl_80409228;

void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void fn_8006B660(void*, int, int);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void getWScale__5MuMsgFUlf(void*, u32, float);
void fn_800B9488(void*, u32, u32);
}

extern "C" void fn_80104C60(void* self, void* data) {
    MsgCfg cfg = lbl_80409228;
    *(void**)((u8*)self + 0xc) = create__5MuMsgFUlQ25Heaps8HeapTypeUl(8, 0x28, 0x2a);
    allocMsgBuf__5MuMsgFUlUl(*(void**)((u8*)self + 0xc), 0x100, 0xd);
    setMsgData__5MuMsgFPv(*(void**)((u8*)self + 0xc), data);

    u8* p = &cfg.data[0];
    for (int i = 0; i < 0xd; i++) {
        float f = p[2] ? lbl_805A27BC : lbl_805A27C0;
        u8* b = (u8*)*(void**)((u8*)self + p[0] * 4 + 4);
        void* c = *(void**)(b + 0x10);
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(*(void**)((u8*)self + 0xc), i, c, p[1], f);
        fn_8006B660(*reinterpret_cast<void**>((u8*)*(void**)((u8*)self + 0xc) + 8), i, 7);
        if (p[2] != 0) {
            setFontColor__5MuMsgFUlUcUcUcUc(*(void**)((u8*)self + 0xc), i, 0, 0, 0, 0xff);
        } else {
            getWScale__5MuMsgFUlf(*(void**)((u8*)self + 0xc), i, lbl_805A27C4);
        }
        fn_800B9488(*(void**)((u8*)self + 0xc), i, 4);
        p += 3;
    }
}