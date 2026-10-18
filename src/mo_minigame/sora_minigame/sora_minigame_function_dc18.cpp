#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_20_DC18(u8* obj) {
    if (obj[0x21] == 0) {
        obj[0x21] = 1;
    }
}
