#pragma force_active on
extern "C" {
void fn_101_10750(void*, void*);
void fn_101_10CC0(short*, const short*);
void fn_101_10830(void*, short*, void*);
}

struct NessSuspendFlags {
    unsigned char flag : 1;
    unsigned char rest : 7;
};

extern "C" void fn_101_107A0(void* self, const short* src, void* accesser) {
    unsigned char* base = static_cast<unsigned char*>(self);
    unsigned char* energy = base + 0xC;
    short local;
    if (src[0] & 1) {
        bool flag = reinterpret_cast<NessSuspendFlags*>(energy + 5)->flag;
        if (flag == true && energy[6] == 0) {
            fn_101_10750(energy, accesser);
        }
    }
    fn_101_10CC0(&local, src);
    fn_101_10830(base + 4, &local, accesser);
}
