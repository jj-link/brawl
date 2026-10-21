#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, u32);

inline void copyVec(float* dst, const float* src) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

extern "C" void fn_73_7434(u8* self) {
    u8* p = self + 0xD0;
    if (p != 0) {
        u8* a = *(u8**)(self + 0x44);
        u8* m = *(u8**)a;
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                *(u8**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                *(u16*)(m + 0x122) = (u16)**(u32**)(p + 0x4);
            }
            u8* src = *(u8**)(self + 0x294);
            if (src != 0) {
                copyVec((float*)(*(u8**)(p + 4) + 8), (float*)src);
                u8* q = *(u8**)(p + 4);
                *(float*)(q + 0x14) = *(float*)(self + 0x298);
                *(float*)(q + 0x18) = *(float*)(self + 0x29c);
                *(float*)(q + 0x1c) = *(float*)(self + 0x2a0);
            }
        }
    }
}
