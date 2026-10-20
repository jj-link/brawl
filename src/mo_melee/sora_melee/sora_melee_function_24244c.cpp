#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_27_24244C(u8* p)
{
    if (p[0x40] == 0) {
        p[0x40] = 1;
        p[0x5e] = 0;
    }
    p[0x5e] = 1;
}
}
