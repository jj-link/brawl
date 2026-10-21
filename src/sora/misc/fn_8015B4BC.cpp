#pragma force_active on
typedef unsigned char u8;

extern "C" u8 lbl_80409798[];

extern "C" void* fn_8015B4BC(char* base, int idx)
{
    u8 var;
    if (idx < 0 || idx > 0x2B) {
        var = 0x23;
    } else {
        var = lbl_80409798[idx];
    }
    return base + var * 0x280 + 4;
}
