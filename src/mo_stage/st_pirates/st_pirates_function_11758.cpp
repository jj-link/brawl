#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
}

extern "C" void fn_52_11758(u8* self) {
    u8* p = self + 0xD0;
    if (p != 0) {
        u32 idx = *(u32*)(self + 0xC0);
        u8* a = *(u8**)(self + 0x44);
        u8* m = *(u8**)(a + idx * 4);
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                u32 v = *(u32*)(self + 0xC4);
                u32* q = *(u32**)(p + 4);
                *q = v;
                *(u8**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(u32**)(p + 4);
                *(u16*)(m + 0x122) = (u16)*q;
            }
            {
                float* dst = *(float**)(p + 4);
                float* src = (float*)(self + 0x160);
                ((float*)((u8*)dst + 0x8))[0] = src[0];
                ((float*)((u8*)dst + 0xc))[0] = src[1];
                ((float*)((u8*)dst + 0x10))[0] = src[2];
            }
        }
    }
}
