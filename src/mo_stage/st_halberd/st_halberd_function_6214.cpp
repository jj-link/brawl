#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
}

extern float lbl_57_rodata_1B4;

struct Blk30 {
    u32 w[12];
};

struct SrcBlk {
    u32 a[7];
    float f;
    u32 b[4];
};

extern "C" void fn_57_6214(u8* self) {
    u8* p = self + 0xD0;
    if (p != 0) {
        u8* a = *(u8**)(self + 0x44);
        u8* m = *(u8**)a;
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                **(u32**)(p + 0x4) = *(u32*)(self + 0xc4);
                *(u8**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                *(u16*)(m + 0x122) = (u16)**(u32**)(p + 0x4);
            }
            SrcBlk* src = *(SrcBlk**)(self + 0x160);
            if (src != 0) {
                src->f = src->f + lbl_57_rodata_1B4;
                SrcBlk* s = *(SrcBlk**)(self + 0x160);
                *(Blk30*)(*(u8**)(p + 0x4) + 0x50) = *(Blk30*)s;
            }
        }
    }
}
