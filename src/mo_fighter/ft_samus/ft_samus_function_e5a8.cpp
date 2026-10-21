#pragma force_active on
extern "C" void fn_94_E558(void* obj, void* arg);
extern "C" short* fn_94_EAC8(short* destination, const short* source);
extern "C" int fn_94_E638(void* obj, short* data, void* arg);

extern "C" void fn_94_E5A8(void* self, short* src, void* arg) {
    unsigned char* p = (unsigned char*)self + 0xC;
    if ((*src & 1) != 0) {
        unsigned char bit = (p[5] >> 7) & 1;
        if ((bool)bit == true && p[6] == 0) {
            fn_94_E558(p, arg);
        }
    }
    short buf[4];
    fn_94_EAC8(buf, src);
    fn_94_E638((unsigned char*)self + 4, buf, arg);
}
