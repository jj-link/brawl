#pragma force_active on
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(int, int, int, int, int);
};

extern "C" void fn_27_77950(int* out);
extern "C" int fn_27_77A88(soNullable*, int, int, int, int, int);

extern "C" int fn_27_779DC(soNullable* self, int a, int b, int c, int d) {
    int flags;
    int r;
    fn_27_77950(&flags);
    int id = flags & 0x7FFFFFFF;
    if (id <= 9999) {
        r = fn_27_77A88(self, id, a, b, c, d);
    } else {
        r = self->slot3(id, a, b, c, d);
    }
    if (flags & 0x80000000) {
        r = (r == 0);
    }
    return r;
}
