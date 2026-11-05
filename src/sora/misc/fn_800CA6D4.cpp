#pragma force_active on
typedef unsigned char u8;
extern "C" u8 fn_800C851C();
inline u8* getLocal(void* self) {
    u8 local = fn_800C851C();
    if (local == 0xFF)
        local = 4;
    return (u8*)self + local * 0x218;
}
extern "C" u8 fn_800CA6D4(void* self, int slot) {
    unsigned int player = *((u8*)self + slot * 8 + 0x4D);
    return *(getLocal(self) + player * 8 + 0xAC);
}