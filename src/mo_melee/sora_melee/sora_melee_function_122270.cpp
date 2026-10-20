#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_122270(char* self, s32 a, u32 b) {
    if (a == 0xc) {
        if (b == 0xc) {
            return *(s32*)(self + 0x458);
        }
        if (b == 0xd) {
            return *(s32*)(self + 0x454);
        }
        if (b & 0x80) {
            return *(s32*)(self + 0x45c);
        }
        return *(s32*)(self + ((b & 0xff) << 2) + 0x424);
    }
    return *(s32*)(self + (a << 2) + 0x348);
}
}
