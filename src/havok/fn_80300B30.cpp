#pragma force_active on
extern "C" void fn_8031830C(void* a, int b);

extern "C" void* fn_80300B30(void* arg0, unsigned char* arg1, int arg2) {
    unsigned char* p = arg1 + 0xC;
    fn_8031830C(p, arg2);
    ((unsigned char*)arg0)[2] = p[2];
    unsigned int size = (p[2] << 3) + ((p[0] + p[1]) << 1);
    return arg1 + ((size + 0x1F) & ~0xF);
}
