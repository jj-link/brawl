#pragma force_active on
struct FtPikminBits {
    int a;
    int b;
    unsigned int c : 10;
    signed int d : 5;
    unsigned int e : 17;
};

extern "C" int fn_113_13A6C(FtPikminBits* p) {
    return p->d;
}
