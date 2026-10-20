#pragma force_active on
extern "C" void fn_113_F8FC(unsigned char* self, void* arg);
extern "C" void fn_113_FD84(short* destination, const short* source);
extern "C" int fn_113_F9DC(unsigned char* self, short* data, void* arg);

struct PikminSub {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char b6;
};

extern "C" void fn_113_F94C(unsigned char* obj, const short* src, void* arg) {
    PikminSub* sub = reinterpret_cast<PikminSub*>(obj + 0xC);
    if ((src[0] & 1) != 0) {
        if ((bool)sub->flag == true && sub->b6 == 0) {
            fn_113_F8FC(obj + 0xC, arg);
        }
    }
    short tmp[4];
    fn_113_FD84(tmp, src);
    fn_113_F9DC(obj + 4, tmp, arg);
}
