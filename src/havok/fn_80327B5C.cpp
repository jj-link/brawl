#pragma force_active on
typedef struct {
    int a;
    int b;
    int c;
} Tmp;

extern Tmp lbl_80488CE8;
extern "C" void fn_802F291C(int, int, int, int, Tmp*, int);

extern "C" void fn_80327B5C(int p1, int p2, int p3, int p4) {
    Tmp t = lbl_80488CE8;
    fn_802F291C(p1, p2, p3, p4, &t, 0);
}
