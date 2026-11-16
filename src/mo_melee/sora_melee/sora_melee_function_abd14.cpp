#pragma force_active on

struct CopyData { int a; int b; int c; short d; short e; };

extern "C" void fn_27_7756C(CopyData* dst, const CopyData* src);
extern "C" void fn_27_77668(CopyData* item, const void* arg);

struct Arr {
    virtual void v0();
    virtual CopyData* get(int i);
    virtual void v2();
    virtual int size();
};

struct Self {
    int a;
    int b;
    int c;
    Arr* arr;
    int key;
};

static int find(Self* self, int key, CopyData*& p, int& i) {
    for (; i < self->arr->size(); i++) {
        p = self->arr->get(i);
        CopyData tmp;
        fn_27_7756C(&tmp, p);
        tmp.c = p->c;
        tmp.d = p->d;
        tmp.e = p->e;
        if (key == tmp.c) return i;
    }
    return -1;
}

extern "C" void fn_27_ABD14(Self* self, const void* arg) {
    int key = self->key;
    if (self->arr->size() > 0) {
        if (key <= -1) {
            fn_27_77668(self->arr->get(self->arr->size() - 1), arg);
        } else {
            CopyData* p;
            int i = 0;
            i = find(self, key, p, i);
            if (i >= 0) {
                fn_27_77668(self->arr->get(i), arg);
            }
        }
    }
}
