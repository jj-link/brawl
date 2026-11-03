#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

extern "C" void fn_66_49D0(void* arg0) {
    u8* s = (u8*)arg0;
    u8* p = s + 0xd0;
    if (p != 0) {
        u8** a = *(u8***)(s + 0x44);
        u8* m = a[*(u32*)(s + 0xc0)];
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                u32* q = *(u32**)(p + 4);
                *q = *(u32*)(s + 0xc4);
                *(u8**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(u32**)(p + 4);
                *(u16*)(m + 0x122) = (u16)*q;
            }
            {
                float* d = *(float**)(p + 4);
                d[2] = *(float*)(s + 0x160);
                d[3] = *(float*)(s + 0x164);
                d[4] = *(float*)(s + 0x168);
            }
            {
                float* d = *(float**)(p + 4);
                d[11] = *(float*)(s + 0x16c);
                d[12] = *(float*)(s + 0x170);
                d[13] = *(float*)(s + 0x174);
            }
            {
                float* d = *(float**)(p + 4);
                d[5] = *(float*)(s + 0x178);
                d[6] = *(float*)(s + 0x17c);
                d[7] = *(float*)(s + 0x180);
            }
        }
    }
}
