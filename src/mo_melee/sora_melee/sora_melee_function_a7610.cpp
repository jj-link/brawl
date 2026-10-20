#pragma force_active on
struct ftInner {
    char pad[0x1c];
    unsigned char b0 : 1;
    unsigned char rest : 7;
};

struct ftOuter {
    void* pad;
    ftInner* inner;
};

extern "C" {
void fn_27_A7610(ftOuter* p, int flag) {
    if (flag == 0) {
        p->inner->b0 = 0;
    }
}
}
