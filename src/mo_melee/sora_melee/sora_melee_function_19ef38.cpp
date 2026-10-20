#pragma force_active on
extern "C" {
struct T {
    int a;
    int b;
    unsigned int f1 : 15;
    unsigned int f2 : 1;
    unsigned int f3 : 16;
};
int fn_27_19EF38(struct T* p) {
    return p->f2;
}
}
