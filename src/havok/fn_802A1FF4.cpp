#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802A213C();
void fn_802A34F8();
void fn_802A3588();
void fn_802A35D0();
void fn_802A20C0();
void fn_802A3138();
void fn_802A2E48();
void fn_802A29A4();
}

typedef void (*Callback)();

struct Entry {
    Callback a, b, c, d;
    bool e, f;

    Entry(Callback aa, Callback bb, Callback cc, Callback dd,
          bool ee, bool ff) : e(false) {
        a = aa;
        b = bb;
        c = cc;
        d = dd;
        e = ee;
        f = ff;
    }
};

extern "C" void fn_802CC0EC(void*, const Entry*, int, int);

extern "C" void fn_802A1FF4(void* self) {
    Entry first(fn_802A213C, fn_802A34F8, fn_802A3588, fn_802A35D0,
                true, true);
    fn_802CC0EC(self, &first, -1, 0x16);

    Entry second(fn_802A20C0, fn_802A3138, fn_802A2E48, fn_802A29A4,
                 false, true);
    fn_802CC0EC(self, &second, 0x16, -1);
}