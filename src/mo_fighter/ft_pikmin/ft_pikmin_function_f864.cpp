#pragma force_active on
extern "C" {
void fn_113_F814(unsigned char* obj, void* arg);
void fn_113_FD84(short* dst, const short* src);
void fn_113_F8F4(unsigned char* obj, short* data, void* arg);
}

struct PikminSub {
    unsigned char pad[5];
    unsigned char enabled : 1;
    unsigned char other : 7;
    unsigned char disabled;
};

extern "C" void fn_113_F864(unsigned char* self, short* src, void* arg) {
    short local;
    PikminSub* sub = reinterpret_cast<PikminSub*>(self + 0xC);
    if (src[0] & 1) {
        bool flag = sub->enabled;
        if (flag == true && sub->disabled == 0) {
            fn_113_F814(reinterpret_cast<unsigned char*>(sub), arg);
        }
    }
    fn_113_FD84(&local, src);
    fn_113_F8F4(self + 4, &local, arg);
}
