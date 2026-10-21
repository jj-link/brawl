#pragma force_active on

typedef unsigned char u8;

extern "C" int fn_80300978(const u8* p) {
    int a = *p++;
    int b = *p++;
    int c = *p;
    return (a + b) * 2 + c * 8 + 4;
}
