#pragma force_active on
struct Base {
    int pad[3];
    int m0c;
    unsigned state : 4;
    unsigned rest : 28;
};
struct Obj : Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};
struct Holder { Obj* o; };
extern "C" Holder* fn_80101384(Holder* h, int n) {
    if (h) {
        Obj* o = h->o;
        if (o && ((((unsigned char*)o)[0x10] >> 2) & 1)) {
            o->v3();
            o->state = 2;
        }
        if (h->o && h) {
            h->o->m0c = 0;
            h->o = 0;
        }
        if (n > 0) delete h;
    }
    return h;
}
