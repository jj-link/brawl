#pragma force_active on
extern "C" char lbl_27_data_20878[];

struct SoaObj {
    void *vt;
    int f4;
    int f8;
    int fc;
};

extern "C" void fn_27_C7744(SoaObj *p, int a, int b)
{
    p->f4 = 0;
    p->vt = lbl_27_data_20878;
    p->f8 = a;
    p->fc = b;
    if (a == 0) {
        p->fc = 0;
    }
}
