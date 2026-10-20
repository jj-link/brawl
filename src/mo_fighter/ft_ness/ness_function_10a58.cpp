#pragma force_active on
extern "C" {
void fn_101_10A08(void*, void*);
void fn_101_10CC0(short*, const short*);
void fn_101_10AE8(void*, short*, void*);
}

extern "C" void fn_101_10A58(unsigned char* self, const short* flags, void* accesser) {
    short local;
    unsigned char* sub = self + 0xC;
    if (flags[0] & 4) {
        unsigned char bit = (sub[5] >> 7) & 1;
        bool flag = bit;
        if (flag == true && sub[6] == 0) {
            fn_101_10A08(sub, accesser);
        }
    }
    fn_101_10CC0(&local, flags);
    fn_101_10AE8(self + 4, &local, accesser);
}
