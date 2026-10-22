#pragma force_active on
struct CopyData { int a; int b; int c; short d; short e; };
extern "C" void fn_27_7756C(CopyData* dst, const CopyData* src);
extern "C" void fn_27_AB41C(short* a, const CopyData* b);

struct Arr {
    virtual void v0();
    virtual CopyData* get(int i);
    virtual void v2();
    virtual int size();
};
struct Holder { int a; int b; Arr* arr; };

static int find(Holder* h, int key) {
    int i = 0;
    for (; i < h->arr->size(); i++) {
        CopyData* p = h->arr->get(i);
        CopyData tmp;
        fn_27_7756C(&tmp, p);
        tmp.c = p->c;
        tmp.d = p->d;
        tmp.e = p->e;
        if (key == tmp.c) return i;
    }
    return -1;
}

extern "C" void fn_27_AC0B8(short* out, Holder* h, int key) {
    int i = find(h, key);
    if (i < 0) { *out = 0; return; }
    int j = find(h, key);
    if (j < 0) { *out = 0; return; }
    fn_27_AB41C(out, h->arr->get(j));
}
