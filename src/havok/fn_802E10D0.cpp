#pragma force_active on
extern "C" {
extern void* lbl_805A0EC8;
void fn_8027EABC(void*, void*, unsigned int, int);

struct S {
    void* f0;
    unsigned short f4;
};

void* fn_802E10D0(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        S* s = (S*)arg0;
        fn_8027EABC(lbl_805A0EC8, arg0, s->f4, 0x2c);
    }
    return arg0;
}
}
