#pragma force_active on

extern "C" {
void fn_8027EABC(void*, void*, unsigned int, int);
void exit__6gfTaskFv(void*);
extern void* lbl_805A0EC8;
extern void* lbl_8049DEC8[3];
}

struct Vec {
    void* data;
    int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15);
    }
};

struct Obj {
    char pad[0x60];
    Vec a;
    Vec b;
};

static void vec_clear(Obj* o, int which) {
    Vec* v = which ? &o->b : &o->a;
    if (v->size != 0) {
        if (v->isOwned()) {
            v->dealloc();
        }
        v->data = 0;
        v->size = 0;
        v->raw = (v->raw & 0x40000000) | 0x80000000;
    }
}

extern "C" void fn_8009A2A8(Obj* self) {
    if (lbl_8049DEC8[0]) {
        vec_clear(self, 0);
        vec_clear(self, 1);
        exit__6gfTaskFv(lbl_8049DEC8[0]);
        lbl_8049DEC8[0] = 0;
    }
}
