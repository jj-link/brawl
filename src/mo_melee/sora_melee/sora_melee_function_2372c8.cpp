#pragma force_active on
struct S {
    int a;
    void* b;
    int c;
    float d;
    int e;
};

extern char lbl_27_data_4C6A0[];
extern const float lbl_27_rodata_3920;

extern "C" void fn_27_2372C8(S* p, int v) {
    p->a = 0;
    p->c = 0;
    p->b = lbl_27_data_4C6A0;
    p->d = lbl_27_rodata_3920;
    p->e = v;
}
