#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802A3C28();
void fn_802A9528();
void fn_802A95B8();
void fn_802A9600();
void fn_802A3D38();
void fn_802A83F8();
void fn_802A7F30();
void fn_802A90C0();
void fn_802A8F50();
}

typedef void (*Callback)();

struct Callbacks {
    Callback a, b, c, d;
    bool e, f;

    Callbacks(Callback aa, Callback bb, Callback cc, Callback dd,
              bool ee, bool ff)
        : a(aa), b(bb), c(cc), d(dd), e(false), f(false) {
        e = ee;
        f = ff;
    }
};

extern "C" void fn_802CC0EC(void*, const Callbacks*, int, int);

extern "C" void fn_802A8E58(void* arg0) {
    Callbacks a(fn_802A3C28, fn_802A9528, fn_802A95B8, fn_802A9600, 1, 0);
    fn_802CC0EC(arg0, &a, 0x18, -1);

    Callbacks b(fn_802A3D38, fn_802A83F8, fn_802A7F30, fn_802A90C0, 0, 0);
    fn_802CC0EC(arg0, &b, -1, 0x18);

    Callbacks c(fn_802A8F50, fn_802A83F8, fn_802A7F30, fn_802A90C0, 0, 1);
    fn_802CC0EC(arg0, &c, 0x18, 0x18);
}
