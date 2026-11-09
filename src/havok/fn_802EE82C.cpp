#pragma force_active on
#pragma use_lmw_stmw on

extern char lbl_80413438[];

struct NestedObj {
    void* f0;
    int f4;
    int f8;
};

struct Obj {
    int f00;
    void* f04;
    void* f08;
    char pad0C[0x14];
    void* f20;
    char pad24[0x4];
    void* f28;
    int f2C;
    char pad30[0x4];
    void* f34;
    int f38;
    char pad3C[0x4];
    void* f40;
    int f44;
    int f48;
    void* f4C;
    char pad50[0x4];
    void* f54;
    void* f58;
    void* f5C;
    void* f60;
    void* f64;
    void* f68;
    void* f6C;
    void* f70;
    NestedObj* f74;
    char pad78[0x54];
    void* fCC;
    int fD0;
    int fD4;
    char padD8[0xC];
    void* fE4;
    int fE8;
    int fEC;
    void* fF0;
    int fF4;
    int fF8;
    void* fFC;
    int f100;
    int f104;
    void* f108;
    int f10C;
    int f110;
    void* f114;
    int f118;
    int f11C;
    void* f120;
    int f124;
    int f128;
    void* f12C;
    int f130;
    int f134;
    void* f138;
    int f13C;
    int f140;
    void* f144;
    int f148;
    int f14C;
    char pad150[0xC];
    void* f15C;
    int f160;
    int f164;
};

class Visitor {
public:
    virtual void unused();
    virtual void object(const char*, int, void*);
    virtual void array(const char*, int, void*, int, int);
    virtual void value(const char*, int, void*);
    virtual void begin(const char*);
    virtual void end();
    virtual void finish();
};

extern "C" void fn_802EE82C(Obj* self, Visitor* visitor) {
    visitor->object(lbl_80413438 + 0x145, 2, self);

    for (int i = self->f2C - 1; i >= 0; --i)
        visitor->value(lbl_80413438 + 0x14D, 8, ((void**)self->f28)[i]);

    for (int i = self->f38 - 1; i >= 0; --i)
        visitor->value(lbl_80413438 + 0x154, 8, ((void**)self->f34)[i]);

    visitor->value(lbl_80413438 + 0x15D, 8, self->f20);

    {
        const char* name = lbl_80413438 + 0x163;
        if (!(self->fD4 & 0x80000000))
            visitor->array(name, 4, self->fCC, self->fD0 * 4, self->fD4 * 4);
    }

    for (int i = 0; i < self->fD0; ++i)
        visitor->value(lbl_80413438 + 0x16F, 2, ((void**)self->fCC)[i]);

    visitor->begin(lbl_80413438 + 0x178);
    visitor->value(lbl_80413438 + 0x181, 4, self->f08);

    {
        const char* name = lbl_80413438 + 0x18C;
        if (!(self->f48 & 0x80000000))
            visitor->array(name, 8, self->f40, self->f44 * 4, self->f48 * 4);
    }

    visitor->value(lbl_80413438 + 0x198, 4, self->f4C);
    visitor->array(lbl_80413438 + 0x1A4, 4, self->f74, 0x20, 0);
    visitor->begin(lbl_80413438 + 0x1A4);

    {
        NestedObj* n = self->f74;
        const char* name = lbl_80413438 + 0x1AC;
        int flags = n->f8;
        if (!(flags & 0x80000000))
            visitor->array(name, 8, n->f0, n->f4 * 0x14, (flags & 0x3FFFFFFF) * 0x14);
    }

    visitor->end();
    visitor->begin(lbl_80413438 + 0x1B7);
    visitor->value(lbl_80413438 + 0x1BF, 4, self->f54);
    visitor->array(lbl_80413438 + 0x1CA, 4, self->f58, 0x104, 0);
    visitor->array(lbl_80413438 + 0x1CA, 4, self->f60, 0xC, 0);
    visitor->array(lbl_80413438 + 0x1CA, 4, self->f5C, 8, 0);
    visitor->array(lbl_80413438 + 0x1CA, 4, self->f64, 8, 0);
    visitor->array(lbl_80413438 + 0x1D5, 4, self->f68, 0x30, 0);
    visitor->value(lbl_80413438 + 0x1DF, 1, self->f6C);
    visitor->value(lbl_80413438 + 0x1E6, 4, self->f70);
    visitor->end();
    visitor->end();
    visitor->begin(lbl_80413438 + 0x1F1);

    {
        const char* name = lbl_80413438 + 0x1FB;
        if (!(self->fEC & 0x80000000))
            visitor->array(name, 4, self->fE4, self->fE8 * 4, self->fEC * 4);
    }
    {
        const char* name = lbl_80413438 + 0x205;
        if (!(self->fF8 & 0x80000000))
            visitor->array(name, 4, self->fF0, self->fF4 * 4, self->fF8 * 4);
    }
    {
        const char* name = lbl_80413438 + 0x211;
        if (!(self->f104 & 0x80000000))
            visitor->array(name, 4, self->fFC, self->f100 * 4, self->f104 * 4);
    }
    {
        const char* name = lbl_80413438 + 0x21E;
        if (!(self->f110 & 0x80000000))
            visitor->array(name, 4, self->f108, self->f10C * 4, self->f110 * 4);
    }
    {
        const char* name = lbl_80413438 + 0x22B;
        if (!(self->f11C & 0x80000000))
            visitor->array(name, 4, self->f114, self->f118 * 4, self->f11C * 4);
    }
    {
        const char* name = lbl_80413438 + 0x238;
        if (!(self->f128 & 0x80000000))
            visitor->array(name, 4, self->f120, self->f124 * 4, self->f128 * 4);
    }
    {
        const char* name = lbl_80413438 + 0x245;
        if (!(self->f134 & 0x80000000))
            visitor->array(name, 4, self->f12C, self->f130 * 4, self->f134 * 4);
    }
    {
        const char* name = lbl_80413438 + 0x252;
        if (!(self->f140 & 0x80000000))
            visitor->array(name, 4, self->f138, self->f13C * 4, self->f140 * 4);
    }
    {
        const char* name = lbl_80413438 + 0x245;
        if (!(self->f14C & 0x80000000))
            visitor->array(name, 4, self->f144, self->f148 * 4, self->f14C * 4);
    }
    {
        const char* name = lbl_80413438 + 0x25F;
        if (!(self->f164 & 0x80000000))
            visitor->array(name, 4, self->f15C, self->f160 * 4, self->f164 * 4);
    }

    visitor->end();
    visitor->finish();
}
