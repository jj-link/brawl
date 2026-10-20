#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* fn_27_1C7B78(void* p, int x) {
    int idx = (*(int*)((u8*)p + 0x18) >> 25) + x;
    if (idx >= 0x21) {
        idx -= 0x21;
    }
    return (u8*)p + idx * 12 + 0x1c;
}
}
