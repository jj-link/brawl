#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
}

struct Blk30 {
    u32 w[12];
};

extern "C" void fn_61_61D4(u8* self) {
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
            u8* src = *(u8**)(self + 0x15c);
            if (src != 0) {
                u8* q = *(u8**)(p + 0x4);
                *(Blk30*)(q + 0x50) = *(Blk30*)src;
            }
        }
    }
}
