#pragma force_active on
struct Data {
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char padding[7];
    signed char a;
    signed char b;
};

extern "C" void fn_27_2AE04C(Data* p) {
    p->flag = 0;
    p->a = -1;
    p->b = -1;
}
