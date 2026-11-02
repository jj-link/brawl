#pragma force_active on
extern "C" {
void __dl__FPv(void*);
extern char lbl_804645A8[];
}

struct Obj {
    virtual void a();
    virtual void b();
    virtual void c();
    char pad[0x69];
    unsigned char flag;
};

extern "C" void* fn_8015CF94(Obj* self, int flag) {
    if (self != 0) {
        *(void**)self = lbl_804645A8;
        if (self->flag != 0) {
            self->c();
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
