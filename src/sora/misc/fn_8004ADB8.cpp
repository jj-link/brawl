#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_8004ADB8(void* obj) {
    u8* self = (u8*)obj;
    if (((self[0x24] >> 4) & 1) != 0) {
        self[0x24] = self[0x24] & ~0x10;
    }
}
