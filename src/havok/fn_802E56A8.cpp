#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern char lbl_80488100[];
extern void* lbl_805A0EC8;

struct Inner {
    virtual ~Inner();
    unsigned short active;
    short refs;
};

struct S {
    char* vt;
    unsigned short sz;
    char pad[0xFA];
    Inner* inner;
};

extern "C" S* fn_802E56A8(S* self, int flags) {
    if (self) {
        Inner* inner = self->inner;
        self->vt = lbl_80488100;
        if (inner && inner->active != 0) {
            inner->refs -= 1;
            if (inner->refs == 0) {
                delete inner;
            }
        }
        if (flags > 0) {
            fn_8027EABC(lbl_805A0EC8, self, self->sz, 0x2c);
        }
    }
    return self;
}
