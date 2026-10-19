#pragma force_active on
typedef unsigned char u8;
extern "C" void fn_66_123D4(u8* base) {
    switch (base[0x150]) {
    case 0:
    case 1:
        base[0x150] = 0xd;
        break;
    case 10:
    case 11:
    case 12:
        base[0x15c] = 1;
        break;
    }
}
