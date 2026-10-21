#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
}

extern "C" void fn_61_DE74(u8* self) {
    u8* p = self + 0xD0;
    if (p != 0) {
        u8* a = *(u8**)(self + 0x44);
        u8* m = *(u8**)a;
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                u32* q = *(u32**)(p + 4);
                *q = *(u32*)(self + 0xc4);
                *(u8**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(u32**)(p + 4);
                *(u16*)(m + 0x122) = (u16)*q;
            }
            float* d = *(float**)(p + 4);
            d[2] = *(float*)(self + 0x170);
            d[3] = *(float*)(self + 0x174);
            d[4] = *(float*)(self + 0x178);
            d = *(float**)(p + 4);
            d[5] = *(float*)(self + 0x17c);
            d[6] = *(float*)(self + 0x180);
            d[7] = *(float*)(self + 0x184);
        }
    }
}
