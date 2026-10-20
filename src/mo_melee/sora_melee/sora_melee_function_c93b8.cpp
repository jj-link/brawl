#pragma force_active on
struct Data {
    unsigned char flag : 1;
    unsigned char other : 7;
    unsigned char padding[3];
    int a;
    int b;
    int c;
    short d;
    short e;
    signed char f;
    signed char g;
};

extern "C" void fn_27_C93B8(Data* p) {
    p->flag = 0;
    p->a = 0;
    p->b = 0;
    p->c = -1;
    p->d = 0;
    p->e = -1;
    p->f = -1;
    p->g = -1;
}
