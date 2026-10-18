#pragma force_active on
struct SoFoo {
    char pad[0x44];
    unsigned char a : 6;
    unsigned char flag : 1;
    unsigned char b : 1;
};

extern "C" {
bool fn_27_B6D30(SoFoo* p) {
    return p->flag;
}
}
