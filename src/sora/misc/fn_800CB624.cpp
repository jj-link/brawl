#pragma force_active on

typedef unsigned char u8;
typedef int s32;

extern "C" u8 fn_800C8548();

extern "C" u8 fn_800CB624(char* self, s32 idx) {
    u8 i = fn_800C8548();
    char* p;
    if (i == 0xFF) {
        p = 0;
    } else {
        p = self + i * 0x218 + 0x70;
    }
    if (p == 0) {
        return 0;
    }
    char* q = p + idx * 0xA + 0xE9;
    return (u8)*q;
}