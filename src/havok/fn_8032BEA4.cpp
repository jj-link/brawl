#pragma force_active on
extern char lbl_80488D58[];

struct Ref {
    void *vtable;
    unsigned short count;
    signed short refs;
};

struct Object {
    void *vtable;
    unsigned short count;
    signed short refs;
    void *vtable1;
    void *vtable2;
    void *vtable3;
    void *vtable4;
    void *vtable6;
    Ref *ref;
};

extern "C" Object *fn_8032BEA4(Object *p, Ref *q) {
    p->refs = 1;
    p->vtable = lbl_80488D58;
    p->vtable1 = lbl_80488D58 + 0x10;
    p->vtable2 = lbl_80488D58 + 0x20;
    p->vtable3 = lbl_80488D58 + 0x30;
    p->vtable4 = lbl_80488D58 + 0x40;
    p->vtable6 = lbl_80488D58 + 0x60;
    p->ref = q;
    if (q != 0 && q->count != 0) {
        q->refs = q->refs + 1;
    }
    return p;
}