#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802AC3D8();
void fn_802AE420();
void fn_802AE4B0();
void fn_802AE4F8();
void fn_802AC4F4();
void fn_802AD7F0();
void fn_802ACC44();
void fn_802B7FD0();
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

extern "C" void fn_802AC30C(void* self) {
    Entry first(fn_802AC3D8, fn_802AE420, fn_802AE4B0, fn_802AE4F8,
                true, false);
    fn_802CC0EC(self, &first, 6, 8);

    Entry second(fn_802AC4F4, fn_802AD7F0, fn_802ACC44, fn_802B7FD0,
                 false, false);
    fn_802CC0EC(self, &second, 8, 6);
}
