#pragma force_active on
extern "C" {
extern void* lbl_805A0EC8;
void fn_8027EABC(void*, void*, unsigned int, int);

struct S {
    int a;
    unsigned short b;
};

void* fn_802E133C(void* arg0, int arg1) {
    S* s = (S*)arg0;
    if (arg0 && arg1 > 0) {
        fn_8027EABC(lbl_805A0EC8, arg0, s->b, 0x2C);
    }
    return arg0;
}
}
