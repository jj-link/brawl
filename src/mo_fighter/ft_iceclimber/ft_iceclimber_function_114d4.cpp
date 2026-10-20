#pragma force_active on
extern "C" {
void fn_105_1119C(unsigned char* obj, void* arg);
short* fn_105_12C6C(short* destination, const short* source);
int fn_105_11564(unsigned char* obj, short* buf, void* arg);
}

extern "C" void fn_105_114D4(unsigned char* self, const short* src, void* arg) {
    unsigned char* sub = self + 0xC;
    if ((src[0] & 1) != 0) {
        unsigned char bit = (sub[5] >> 7) & 1;
        if ((bool)bit == 1 && sub[6] == 0) {
            fn_105_1119C(sub, arg);
        }
    }
    short buf[4];
    fn_105_12C6C(buf, src);
    fn_105_11564(self + 4, buf, arg);
}
