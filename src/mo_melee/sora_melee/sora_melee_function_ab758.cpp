#include <types.h>
#pragma force_active on

struct CopyData { int a; int b; int c; short d; short e; };

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual CopyData* slot1(int);
    virtual void slot2();
    virtual int slot3();
};

struct Outer { int a; int b; int c; Object_vptr_0* arr; int result; };

extern "C" void fn_27_7756C(CopyData*, const CopyData*);
extern "C" void fn_27_7773C(void*);
extern "C" void fn_27_77588(void*, int);
extern "C" int fn_27_AB900(void*, int, int, s16*, int);

static int find(Outer* self, int key) {
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

extern "C" int fn_27_AB758(Outer* self, int id, int prio, int arg3, s16* arg4) {
    if (id > -1 && find(self, id) >= 0) {
        int i = find(self, id);
        unsigned char* p = (unsigned char*)self->arr->slot1(i);
        fn_27_7773C(p);
        fn_27_77588(p, arg3);
        *p |= 0x80;
        self->result = id;
    } else {
        s16 sp8 = *arg4;
        self->result = fn_27_AB900((char*)self + 4, arg3, id, &sp8, prio);
    }
    return self->result;
}
