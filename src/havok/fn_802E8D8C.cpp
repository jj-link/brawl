#pragma force_active on

extern "C" void fn_802F0570();
extern "C" char lbl_80413248[];

class IVirt {
public:
    virtual void v0();
    virtual void v1();
    virtual void v4(void*, int, int, int, int);
};

struct Obj {
    char pad0[0x58];
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
};

extern "C" void fn_802E8D8C(Obj* self, IVirt* obj) {
    fn_802F0570();

    char* base = lbl_80413248;
    if (!(self->f60 & 0x80000000)) {
        obj->v4(base, 4, self->f58, self->f5c * 4, self->f60 * 4);
    }

    char* base2 = lbl_80413248 + 0xd;
    if (!(self->f6c & 0x80000000)) {
        obj->v4(base2, 4, self->f64, self->f68 * 4, self->f6c * 4);
    }
}
