#pragma force_active on
#pragma use_lmw_stmw on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void __dt__14Class_8027D01CFv(void*, int);
extern void* lbl_805A0EC8;
extern unsigned char lbl_80488F30[];
class Heap {
public:
    virtual void vf0();
    virtual void vf1(void*);
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void*, unsigned int, int);
};
extern Heap* lbl_805A0EB8;
struct Arr {
    void* data;
    int count;
    unsigned int raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
};
class Obj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    unsigned short type;
    unsigned int u8;
    char pad0C[0xC];
    Arr a18;
    Arr a24;
    Arr a30;
    Arr a3C;
};
struct Entry12 {
    void* p;
    unsigned int a;
    unsigned int b;
};
extern "C" Obj* fn_80331F60(Obj* self, int flag) {
    int i;
    if (self != 0) {
        *(void**)self = lbl_80488F30;
        self->vf3();
        Heap* heap = lbl_805A0EB8;
        for (i = 0; i < self->a18.count; i++) {
            heap->vf1(((void**)self->a18.data)[i]);
        }
        for (i = 0; i < self->a24.count; i++) {
            Entry12* e = &((Entry12*)self->a24.data)[i];
            heap->free(e->p, e->a, e->b);
        }
        lbl_805A0EB8->vf1((void*)self->u8);
        if ((unsigned int)self + 0x3c) {
            if (self->a3C.isOwned()) {
                fn_8027EABC(lbl_805A0EC8, self->a3C.data, self->a3C.raw << 3, 0x15);
            }
        }
        if ((unsigned int)self + 0x30) {
            if (self->a30.isOwned()) {
                fn_8027EABC(lbl_805A0EC8, self->a30.data, self->a30.raw << 3, 0x15);
            }
        }
        if ((unsigned int)self + 0x24) {
            if (self->a24.isOwned()) {
                fn_8027EABC(lbl_805A0EC8, self->a24.data, (self->a24.raw & 0x3FFFFFFF) * 12, 0x15);
            }
        }
        if ((unsigned int)self + 0x18) {
            if (self->a18.isOwned()) {
                fn_8027EABC(lbl_805A0EC8, self->a18.data, self->a18.raw << 2, 0x15);
            }
        }
        if ((unsigned int)self + 0xc) {
            __dt__14Class_8027D01CFv((char*)self + 0xc, -1);
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x13);
        }
    }
    return self;
}