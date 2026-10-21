#pragma force_active on
extern "C" void fn_118_CF94(unsigned char*, void*);
extern "C" void fn_118_D24C(short*, short*);
extern "C" void fn_118_D074(unsigned char*, short*, void*);

extern "C" void fn_118_CFE4(unsigned char* self, short* src, void* arg) {
    short buf[4];
    unsigned char* p = self + 0xC;
    if (src[0] & 4) {
        unsigned char bit = (p[5] >> 7) & 1;
        bool flag;
        flag = bit;
        if (flag == 1 && p[6] == 0) {
            fn_118_CF94(p, arg);
        }
    }
    fn_118_D24C(buf, src);
    fn_118_D074(self + 4, buf, arg);
}
