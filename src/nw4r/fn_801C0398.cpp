#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
void fn_80203A10(void* a, void* b);

void fn_801C0398(void* self, void* unused, u32* src) {
    u32 tmp[3];
    tmp[0] = src[0];
    tmp[1] = src[1];
    tmp[2] = src[2];
    fn_80203A10(tmp, (u8*)self + 0x24);
}
}
