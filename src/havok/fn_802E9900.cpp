#pragma use_lmw_stmw on
#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void fn_802F0668(void*);
extern char lbl_804882F0[];
extern void* lbl_805A0EC8;
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
struct Arr {
    void* data;
    int size;
    unsigned int raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
};
struct Obj {
    void* vtable;
    unsigned short type;
    char pad[2];
    Arr a08;
    Arr a14;
    Arr a20;
    Arr a2c;
};
extern "C" Obj* fn_802E9900(Obj* self, int flag) {
    if (self) {
        int count = self->a08.size;
        self->vtable = lbl_804882F0;
        for (int i = 0; i < count; i++) {
            fn_802F0668(((void**)self->a08.data)[i]);
        }
        int count2 = self->a2c.size;
        for (int i = 0; i < count2; i++) {
            fn_802F0668(((void**)self->a2c.data)[i]);
        }
        int count3 = self->a14.size;
        for (int i = 0; i < count3; i++) {
            Object_vptr_0* ref = ((Object_vptr_0**)self->a14.data)[i];
            if (ref->active != 0) {
                if (--ref->count == 0 && ref != 0) ref->slot0(1);
            }
        }
        int count4 = self->a20.size;
        for (int i = 0; i < count4; i++) {
            Object_vptr_0* ref = ((Object_vptr_0**)self->a20.data)[i];
            if (ref) {
                if (ref->active != 0) {
                    if (--ref->count == 0 && ref != 0) ref->slot0(1);
                }
            }
        }
        if ((unsigned int)self + 0x2c && self->a2c.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a2c.data, self->a2c.raw << 2, 0x15);
        if ((unsigned int)self + 0x20 && self->a20.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a20.data, self->a20.raw << 2, 0x15);
        if ((unsigned int)self + 0x14 && self->a14.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a14.data, self->a14.raw << 2, 0x15);
        if ((unsigned int)self + 0x08 && self->a08.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a08.data, self->a08.raw << 2, 0x15);
        if (flag > 0) lbl_805A0EB8->slot5(self, self->type, 0x2d);
    }
    return self;
}