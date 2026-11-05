#pragma force_active on
#pragma use_lmw_stmw on

class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4(void*, unsigned short, int);
};

class Class_80453E48 {
public:
    virtual void fn_800651CC(int);
    virtual void fn_8004755C();
    virtual void fn_80065454();
    virtual void fn_80065300();
    virtual void fn_80065450();
    virtual void fn_8006544C();
    unsigned short m04;
    short m06;
};

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern char lbl_804872A8[];
extern void* lbl_805A0EC8;
extern Class_8042B6D0* lbl_805A0EB8;

struct Array {
    void* data;
    int count;
    unsigned int raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw * 8, 0x15); }
};

struct Self {
    void* vtable;
    unsigned short type;
    char pad06[6];
    Class_80453E48* entries[8][8];
    char pad10C[0x1c18 - 0x10c];
    Array array;
};

extern "C" void fn_802CBF38(Self*);

extern "C" Self* fn_802CBFDC(Self* self, int flag) {
    if (self) {
        self->vtable = lbl_804872A8;
        fn_802CBF38(self);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                Class_80453E48* e = self->entries[i][j];
                if (e && e->m04 != 0) {
                    if (--e->m06 == 0 && e != 0) {
                        e->fn_800651CC(1);
                    }
                }
            }
        }
        if ((char*)&self->array != 0 && self->array.isOwned())
            self->array.dealloc();
        if (flag > 0)
            lbl_805A0EB8->fn_801AB1C4(self, self->type, 0x25);
    }
    return self;
}
