#pragma force_active on
typedef unsigned char u8;

extern "C" {
int fn_27_24D368(void* self, int idx) {
    u8* base = *(u8**)((u8*)self + 0x44);
    u8 a = *(u8*)(base + idx * 0x5c + 0x9b);
    u8* p = *(u8**)((u8*)self + 0xcc) + a * 0x2ac;
    signed char v = *(signed char*)(p + 0x2e);
    if (v < 0) {
        return 1;
    }
    return v;
}
}
