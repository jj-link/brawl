#pragma force_active on
extern "C" {
void fn_802AF4C0();
void fn_802B1454();
void fn_802B14E4();
void fn_802B152C();
void fn_802AF3F0();
void fn_802AFB74();
void fn_802AF7D0();
void fn_802AFD44();
void fn_802CC0EC(void*, void*, int, int);
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

extern "C" void fn_802AF698(void* self) {
    Entry first((Callback)fn_802AF4C0, (Callback)fn_802B1454,
                (Callback)fn_802B14E4, (Callback)fn_802B152C,
                true, true);
    fn_802CC0EC(self, &first, 13, 1);

    Entry second((Callback)fn_802AF3F0, (Callback)fn_802AFB74,
                 (Callback)fn_802AF7D0, (Callback)fn_802AFD44,
                 false, true);
    fn_802CC0EC(self, &second, 1, 13);
}
