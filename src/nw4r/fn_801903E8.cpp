#pragma force_active on
extern "C" void fn_8018CD30(void* p, unsigned int arg1);
extern "C" void fn_8018CC6C(void* p, unsigned int arg1, unsigned int arg2);

extern "C" void fn_801903E8(char** arg0, int arg1, unsigned int arg2)
{
    int shift = 9;
    int index = arg1 / 2;
    char* p = *arg0;
    p += index * 0x30;
    char* base = p + 0x80;

    if (arg1 & 1) {
        shift = 0x13;
    }

    unsigned int mask = 0x1F << shift;
    fn_8018CD30(base, mask);
    fn_8018CC6C(base + 5, ((index + 0xF6) << 24) | (arg2 << shift),
                mask | 0xFF000000);
}
