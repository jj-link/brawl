#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802C0B80();
void fn_802B0FE0();
void fn_802B1028();
void fn_802B1070();
void fn_802C0B04();
void fn_802C1AB8();
void fn_802C13D0();
void fn_802C1738();
void fn_802B86B8();
void fn_802B873C();
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

extern "C" void fn_802B85EC(void* self) {
    Entry second(fn_802B86B8, fn_802C1AB8, fn_802C13D0, fn_802C1738,
                 true, true);
    fn_802CC0EC(self, &second, 0xC, -1);

    Entry first(fn_802B873C, fn_802B0FE0, fn_802B1028, fn_802B1070,
                false, true);
    fn_802CC0EC(self, &first, -1, 0xC);
}