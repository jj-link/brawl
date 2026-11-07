#pragma force_active on

extern "C" void fn_802F0668(void*);
extern unsigned char lbl_80487BB8[];

class Object_vptr_0 {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void*, unsigned short, int);
    unsigned short active;
    short count;
};

extern Object_vptr_0* lbl_805A0EB8;

struct Obj {
    void* vtable;
    unsigned short type;
    char pad6[6];
    Object_vptr_0* c;
    char pad10[4];
    void* p14;
    void* p18;
};

extern "C" Obj* fn_802DE7E0(Obj* self, int flag) {
    if (self) {
        void* p = self->p14;
        self->vtable = lbl_80487BB8;
        if (p) {
            fn_802F0668(p);
        }
        if (self->p18) {
            fn_802F0668(self->p18);
        }
        Object_vptr_0* c = self->c;
        if (c != 0) {
            if (c->active != 0) {
                c->count = c->count - 1;
                if (c->count == 0 && c != 0) {
                    c->slot0(1);
                }
            }
        }
        if (flag > 0) {
            lbl_805A0EB8->slot5(self, self->type, 0x2a);
        }
    }
    return self;
}
