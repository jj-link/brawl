#pragma force_active on
extern "C" void fn_802EE6C8(void* self, unsigned int key);

struct Obj {
    virtual void v0(int);
    unsigned short unk4;
    short unk6;
    int pad8;
    int pad12;
    void* unk10;
};

extern "C" void fn_802E972C(Obj* self) {
    void* p = self;
    if (self != 0) {
        p = (char*)self + 8;
    }
    fn_802EE6C8(self->unk10, (unsigned int)p);
    if (self->unk4 != 0) {
        if (--self->unk6 == 0 && self != 0) {
            self->v0(1);
        }
    }
}
