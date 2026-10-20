#pragma force_active on
extern "C" void fn_118_D164(void*, void*);
extern "C" void fn_118_D24C(short*, short*);
extern "C" void fn_118_D244(void*, short*, void*);

extern "C" void fn_118_D1B4(void* self, short* src, void* c) {
    short buf[4];
    unsigned char* p = static_cast<unsigned char*>(self) + 0xc;
    if (*src & 4) {
        unsigned char bit = (p[5] >> 7) & 1;
        bool flag = bit;
        if (flag == true && p[6] == 0) {
            fn_118_D164(p, c);
        }
    }
    fn_118_D24C(buf, src);
    fn_118_D244(static_cast<unsigned char*>(self) + 0x4, buf, c);
}
