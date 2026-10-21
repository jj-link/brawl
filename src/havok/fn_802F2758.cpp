#pragma force_active on
extern "C" {

struct Lbl {
    int a;
    int b;
    int c;
};

extern Lbl lbl_80488618;
extern void fn_802F291C(int, int, int, int, Lbl*, int);

void fn_802F2758(int a, int b, int c, int d, int e) {
    Lbl local = lbl_80488618;
    fn_802F291C(a, b, c, d, &local, e);
}

}
