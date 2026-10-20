#pragma force_active on
extern "C" {
void fn_101_10838(void* a, void* b);
void fn_101_10CC0(short* dst, const short* mask);
void fn_101_10918(void* a, short* b, void* c);
}

struct NessByteFlag {
    unsigned char hi : 1;
    unsigned char lo : 7;
};

extern "C" void fn_101_10888(unsigned char* self, const short* flags, void* accesser) {
    unsigned char* sub = self + 0xC;
    if ((*flags & 1) != 0) {
        NessByteFlag* f = reinterpret_cast<NessByteFlag*>(sub + 5);
        bool bit = f->hi;
        if (bit == true && sub[6] == 0) {
            fn_101_10838(sub, accesser);
        }
    }
    short local;
    fn_101_10CC0(&local, flags);
    fn_101_10918(self + 4, &local, accesser);
}
