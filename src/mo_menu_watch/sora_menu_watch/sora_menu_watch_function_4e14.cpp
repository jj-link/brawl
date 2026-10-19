#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_80155BD0(void* p);

extern "C" void fn_15_4E14(u8* self) {
    if (self[0xd59] == 0) {
        fn_80155BD0(*(void**)(self + 0xd5c));
    }
    *(u32*)(self + 0x4ec) = 6;
}
