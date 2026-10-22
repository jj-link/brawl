#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* fn_800F1820(u8* a, u8* b, u8* c, u8* d, int e, int f, int g, int h);
void fn_8010A598(u8* self, int b);

void fn_8010B6BC(u8* self) {
    *(void**)(self + 0x12c) = fn_800F1820(self + 0x104, self + 0x10c, *(u8**)(self + 0x108), *(u8**)(self + 0x110), 1, 0x28, 0x2a, 6);
    fn_8010A598(self, 0);
}
}
