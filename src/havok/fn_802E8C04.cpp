#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void fn_802E841C(void*);
extern char lbl_80488258[];
extern char lbl_804885E8[];
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
    char pad6[0x16];
    Object_vptr_0* ref1c;
    char pad20[0x20];
    Arr a40;
    Arr a4c;
    Arr a58;
    Arr a64;
};
extern "C" Obj* fn_802E8C04(Obj* self, int flag) {
    if (self) {
        self->vtable = lbl_80488258;
        fn_802E841C(self);
        if ((unsigned int)self + 0x64) {
            if (self->a64.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a64.data, self->a64.raw << 2, 0x15);
        }
        if ((unsigned int)self + 0x58) {
            if (self->a58.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a58.data, self->a58.raw << 2, 0x15);
        }
        if (self) {
            Object_vptr_0* ref = self->ref1c;
            self->vtable = lbl_804885E8;
            if (ref) {
                if (ref->active != 0) {
                    ref->count -= 1;
                    if (ref->count == 0) {
                        if (ref != 0) ref->slot0(1);
                    }
                }
            }
            if ((unsigned int)self + 0x4c) {
                if (self->a4c.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a4c.data, self->a4c.raw << 4, 0x15);
            }
            if ((unsigned int)self + 0x1c) {
                if ((unsigned int)self + 0x40 && self->a40.isOwned()) fn_8027EABC(lbl_805A0EC8, self->a40.data, self->a40.raw << 3, 0x15);
            }
        }
        if (flag > 0) lbl_805A0EB8->slot5(self, self->type, 0x2f);
    }
    return self;
}