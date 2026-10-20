#pragma force_active on
extern "C" void fn_27_19B308(void *p, unsigned int v) {
    struct F {
        unsigned int a : 5;
        unsigned int b : 5;
        unsigned int c : 22;
    };
    F *f = (F *)((char *)p + 8);
    f->b = v;
}
