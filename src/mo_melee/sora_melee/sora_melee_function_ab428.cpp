#pragma force_active on
#include <types.h>
struct CopyData { int a; int b; int c; short d; short e; };
extern "C" void fn_27_7756C(CopyData*, const CopyData*);
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual CopyData* slot1(int);
    virtual void slot2();
    virtual int slot3();
};
struct Holder { int a; int b; int c; Object_vptr_0* arr; };
static int find(Holder* self, int key) {
    int i = 0;
    for (; i < self->arr->slot3(); i++) {
        CopyData* p = self->arr->slot1(i);
        CopyData tmp;
        fn_27_7756C(&tmp, p);
        tmp.c = p->c;
        tmp.d = p->d;
        tmp.e = p->e;
        if (key == tmp.c) return i;
    }
    return -1;
}
extern "C" void fn_27_AB428(Holder* self, int key) {
    int i = find(self, key);
    if (i >= 0) {
        unsigned char* q = (unsigned char*)self->arr->slot1(i);
        *q |= 0x80;
    }
}