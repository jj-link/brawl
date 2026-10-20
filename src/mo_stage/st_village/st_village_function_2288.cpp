#pragma force_active on
struct Village70 {
    char pad[0x6c];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

extern "C" int fn_70_2288(Village70* p) {
    return p->b4;
}
