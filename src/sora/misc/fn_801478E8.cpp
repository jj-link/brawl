#pragma force_active on
extern "C" void fn_80147F10(void*, unsigned char, int);

extern "C" int fn_801478E8(void* arg0, unsigned char arg1) {
    ((unsigned char*)arg0)[0x3421] = arg1;
    fn_80147F10(arg0, arg1, 1);
    ((unsigned char*)arg0)[0x3411] = 1;
    ((unsigned char*)arg0)[0x3412] = 1;
    return 1;
}
