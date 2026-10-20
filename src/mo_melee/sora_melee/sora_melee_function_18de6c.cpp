#pragma force_active on
struct fn27Flags {
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 6;
};

extern "C" void fn_27_18DE6C(unsigned char* p, unsigned int v) {
    ((fn27Flags*)(p + 0xa4))->b = v;
}
