#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
}

extern "C" void fn_78_2B54(u8* self) {
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
            u8* q = *(u8**)(p + 0x4);
            *(float*)(q + 0x2c) = *(float*)(self + 0x160);
            *(float*)(q + 0x30) = *(float*)(self + 0x164);
            *(float*)(q + 0x34) = *(float*)(self + 0x168);
        }
    }
}
