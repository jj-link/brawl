#pragma force_active on
extern "C" {
void fn_101_10920(void*, void*);
void fn_101_10CC0(short*, const short*);
void fn_101_10A00(void*, short*, void*);
}

extern "C" void fn_101_10970(unsigned char* self, const short* flags, void* accesser) {
    unsigned char* sub = self + 0xC;
    if ((flags[0] & 2) != 0) {
        unsigned char b = (sub[5] >> 7) & 1;
        bool bit = b;
        if (bit == true) {
            if (sub[6] == 0) {
                fn_101_10920(sub, accesser);
            }
        }
    }
    short local;
    fn_101_10CC0(&local, flags);
    fn_101_10A00(self + 4, &local, accesser);
}
