#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_801BC66C(u8* obj) {
    if (obj[0x65] == 0) {
        obj[0x64] = 1;
    }
}
