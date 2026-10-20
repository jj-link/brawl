#pragma force_active on
extern "C" void fn_118_D07C(unsigned char* p, void* arg);
extern "C" void fn_118_D24C(short* dst, short* src);
extern "C" void fn_118_D15C(unsigned char* p, short* src, void* arg);

extern "C" void fn_118_D0CC(unsigned char* self, short* src, void* arg) {
    short buf[4];
    unsigned char* p = self + 0xC;
    if (src[0] & 0x8) {
        unsigned char bit = (p[5] >> 7) & 1;
        bool flag;
        flag = bit;
        if (flag == 1 && p[6] == 0) {
            fn_118_D07C(p, arg);
        }
    }
    fn_118_D24C(buf, src);
    fn_118_D15C(self + 0x4, buf, arg);
}
