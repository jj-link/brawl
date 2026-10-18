#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void fn_8_904(u8* self);
}

extern "C" void fn_8_904(u8* self) {
    u8* sub = *(u8**)(self + 0x1ac);
    *(u32*)(sub + 0x1bf4) = 1;
}
