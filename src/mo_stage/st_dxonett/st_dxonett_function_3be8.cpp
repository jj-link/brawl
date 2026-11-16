#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
}

extern "C" const float lbl_78_rodata_A8;
extern "C" const float lbl_78_rodata_C8;

extern "C" void fn_78_3BE8(u8* self) {
    u8* p = self + 0xD0;
    if (p != 0) {
        u8** a = *(u8***)(self + 0x44);
        u8* m = a[*(u32*)(self + 0xc0)];
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
            u8* d = *(u8**)(p + 4);
            u8* r6 = *(u8**)(self + 0x158);
            *(float*)(d + 0x8) = *(float*)(r6 + 0x54);
            *(float*)(d + 0xc) = *(float*)(r6 + 0x58);
            *(float*)(d + 0x10) = *(float*)(r6 + 0x5c);
            *(float*)(*(u8**)(p + 4) + 0xc) = *(float*)(*(u8**)(p + 4) + 0xc) + lbl_78_rodata_C8;
            *(float*)(*(u8**)(p + 4) + 0x10) = lbl_78_rodata_A8;
        }
    }
}
