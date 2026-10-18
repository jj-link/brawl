#pragma force_active on
struct FtBits {
    unsigned char pad[0xa4];
    unsigned char a : 1;
    unsigned char b : 1;
};

extern "C" int fn_115_16FA0(FtBits* p) {
    return p->b != 0;
}
