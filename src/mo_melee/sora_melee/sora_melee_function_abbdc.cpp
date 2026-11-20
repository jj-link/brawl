#pragma force_active on
struct CopyData { int a; int b; int c; short d; short e; };
extern "C" void fn_27_7756C(CopyData* dst, const CopyData* src);
extern "C" void fn_27_77668(CopyData* p, void* q);

class Arr {
public:
    virtual void v0();
    virtual CopyData* get(int i);
    virtual void v2();
    virtual int size();
};
struct Holder { char pad[0xc]; Arr* arr; };

static int find(Holder* self, int id) {
    int i = 0;
    for (; i < self->arr->size(); i++) {
        CopyData* elem = self->arr->get(i);
        CopyData tmp;
        fn_27_7756C(&tmp, elem);
        tmp.c = elem->c;
        tmp.d = elem->d;
        tmp.e = elem->e;
        if (id == tmp.c) return i;
    }
    return -1;
}
extern "C" void fn_27_ABBDC(Holder* self, int id, void* arg2) {
    if (self->arr->size() > 0) {
        if (id <= -1) {
            fn_27_77668(self->arr->get(self->arr->size() - 1), arg2);
            return;
        }
        int i = find(self, id);
        if (i >= 0) {
            fn_27_77668(self->arr->get(i), arg2);
        }
    }
}