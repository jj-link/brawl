#pragma force_active on
extern "C" {
void fn_116_D344(void* self, void* arg);
void fn_116_D99C(short* destination, const short* source);
void fn_116_D424(void* self, const short* data, void* arg);
}

struct FtPokeFlags {
    unsigned char enabled : 1;
    unsigned char pad : 7;
};

extern "C" void fn_116_D394(unsigned char* self, const short* source, void* arg) {
    unsigned char* sub = self + 0xC;
    short local[4];
    if ((source[0] & 1) != 0) {
        FtPokeFlags* f = reinterpret_cast<FtPokeFlags*>(sub + 5);
        bool e = f->enabled;
        if (e == true && sub[6] == 0) {
            fn_116_D344(sub, arg);
        }
    }
    fn_116_D99C(local, source);
    fn_116_D424(self + 4, local, arg);
}
