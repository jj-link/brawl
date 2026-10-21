#pragma force_active on
typedef unsigned char u8;

extern "C" {
u8 fn_8006A750(void* arg0, void** arg1) {
    u8* temp_r6 = *(u8**)((u8*)arg0 + 0x1d0);
    u8 temp_r3 = temp_r6[0x1c];
    temp_r6[0x1c] = 0;
    *arg1 = temp_r6 + 0x18;
    return temp_r3;
}
}
