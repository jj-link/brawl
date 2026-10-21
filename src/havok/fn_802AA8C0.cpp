#pragma force_active on
#pragma use_lmw_stmw on
extern "C" {
void fn_802A9D54();
void fn_802A9528();
void fn_802A95B8();
void fn_802A9600();
void fn_802A9E74();
void fn_802A83F8();
void fn_802A7F30();
void fn_802A90C0();
void fn_802A8F50();
}
struct Entry {
    void (*a)();
    void (*b)();
    void (*c)();
    void (*d)();
    bool e;
    bool f;
};
extern "C" void fn_802CC0EC(void*, const Entry*, int, int);
extern "C" void fn_802AA8C0(void* self) {
    Entry first;
    first.a = fn_802A9D54;
    first.b = fn_802A9528;
    first.c = fn_802A95B8;
    first.d = fn_802A9600;
    first.e = 1;
    first.f = 1;
    fn_802CC0EC(self, &first, 0x18, 1);
    Entry second;
    second.f = 0;
    second.a = fn_802A9E74;
    second.b = fn_802A83F8;
    second.c = fn_802A7F30;
    second.d = fn_802A90C0;
    second.e = 0;
    second.f = 1;
    fn_802CC0EC(self, &second, 1, 0x18);
    Entry third;
    third.a = fn_802A8F50;
    third.b = fn_802A83F8;
    third.c = fn_802A7F30;
    third.d = fn_802A90C0;
    third.e = 0;
    third.f = 1;
    fn_802CC0EC(self, &third, 0x18, 0x18);
}
