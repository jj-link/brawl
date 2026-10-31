#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_8009EF38(void*);

extern "C" void fn_27_B1C68(void* self) {
    u8* p = *(u8**)((u8*)self + 4);
    u32 v = *(u32*)(p + 8);
    if (((v >> 13) & 1) == 1) {
        fn_8009EF38(p);
    }
}
