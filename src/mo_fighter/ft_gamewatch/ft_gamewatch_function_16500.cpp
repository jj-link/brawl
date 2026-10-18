#pragma force_active on
struct FtGwObj {
    unsigned char pad[0xa4];
    unsigned char f7 : 1;
    unsigned char f6 : 1;
    unsigned char f5 : 1;
    unsigned char f4 : 1;
    unsigned char f3 : 1;
    unsigned char f2 : 1;
    unsigned char f1 : 1;
    unsigned char f0 : 1;
};

extern "C" {
int fn_107_16500(FtGwObj* p) {
    return p->f6 != 0;
}
}
