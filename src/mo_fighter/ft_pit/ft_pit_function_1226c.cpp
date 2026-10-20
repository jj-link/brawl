#pragma force_active on
extern "C" {
void fn_112_1221C(unsigned char* self, void* arg);
void fn_112_125BC(short* dst, const short* src);
int fn_112_122FC(unsigned char* self, short* src, void* arg);
}

struct FtPitFlags {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char disabled;
};

extern "C" void fn_112_1226C(unsigned char* self, const short* src, void* arg) {
    short tmp[2];
    FtPitFlags* p = reinterpret_cast<FtPitFlags*>(self + 0xc);
    if ((src[0] & 1) != 0) {
        bool flag = p->flag;
        if (flag == true && p->disabled == 0) {
            fn_112_1221C(self + 0xc, arg);
        }
    }
    fn_112_125BC(tmp, src);
    fn_112_122FC(self + 4, tmp, arg);
}
