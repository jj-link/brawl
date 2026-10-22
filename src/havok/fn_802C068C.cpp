#pragma force_active on
extern "C" void fn_802CC0EC(void* self, void* tbl, int a, int b);
extern "C" void fn_802C07D0(void);
extern "C" void fn_802C0A08(void);
extern "C" void fn_802C0A2C(void);
extern "C" void fn_802C0A34(void);

struct Tbl {
    void* p[4];
    char a;
    char b;
};

extern "C" void fn_802C068C(void* self) {
    Tbl t;
    t.a = 0;
    t.p[0] = (void*)fn_802C07D0;
    t.p[1] = (void*)fn_802C0A08;
    t.p[2] = (void*)fn_802C0A2C;
    t.p[3] = (void*)fn_802C0A34;
    t.b = 1;
    fn_802CC0EC(self, &t, 0x1A, -1);
    fn_802CC0EC(self, &t, -1, 0x1A);
}
