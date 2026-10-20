#pragma force_active on
extern "C" void fn_27_CE1E4(unsigned int *p, unsigned int v) {
    struct W {
        unsigned int hi : 8;
        unsigned int mid : 8;
        unsigned int lo : 16;
    };
    W *w = (W *)&p[2];
    w->mid = v;
}
