#pragma force_active on
struct S {
    unsigned char pad[0x50];
    unsigned char flag : 1;
    unsigned char rest : 7;
};

extern "C" void fn_27_2E7E8(S* p, unsigned int flag) {
    p->flag = flag;
}
