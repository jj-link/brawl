#pragma force_active on
extern char lbl_80486440[];

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void*, unsigned short, int);
};
extern Object_vptr_0* lbl_805A0EB8;

struct Ref {
    virtual void destroy(int);
    unsigned short active;
    short refs;
};
struct Obj {
    void* vt;
    unsigned short type;
    Ref* ref;
};

extern "C" Obj* fn_80280784(Obj* self, int flag) {
    if (self) {
        Ref* ref = self->ref;
        self->vt = lbl_80486440;
        if (ref && ref->active != 0) {
            ref->refs -= 1;
            if (ref->refs == 0 && ref != 0)
                ref->destroy(1);
        }
        if (flag > 0)
            lbl_805A0EB8->slot5(self, self->type, 0x18);
    }
    return self;
}