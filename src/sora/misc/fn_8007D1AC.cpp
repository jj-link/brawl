#pragma force_active on
extern "C" {
extern unsigned char g_thpObject[];

unsigned char fn_8007D1AC(void) {
    return g_thpObject[0xA4];
}
}
