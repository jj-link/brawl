#include <types.h>
#pragma force_active on

struct Group {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void remove(int);
    char pad[0xE0];
    int count;
};

struct Dispatcher {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(void*);
};

extern "C" {
extern Dispatcher* lbl_805A02DC;
void fn_8007291C(void*);

void fn_800E1384(char* self) {
    char* a;
    char* b;
    int j;
    int i;
    int k;

    Group* group = *(Group**)(self + 0xF0);
    while (group->count != 0) {
        if (group->count != 0) {
            group->remove(group->count - 1);
        }
    }

    char* p = self;
    for (i = 0; i < 3; i++) {
        void* ptr = *(void**)(p + 0xF0);
        if (ptr != 0) {
            lbl_805A02DC->f13(ptr);
        }
        p += 4;
    }

    char* q = self;
    for (k = 0; k < 50; k++) {
        void* ptr = *(void**)(q + 0x28);
        if (ptr != 0) {
            lbl_805A02DC->f13(*(void**)((char*)ptr + 0x10));
        }
        q += 4;
    }

    fn_8007291C(self + 0x3A8);

    ((unsigned char*)self)[0x3A0] = 0;
    a = self + 0x3EC;
    b = self;
    for (j = 0; j < 4; j++) {
        fn_8007291C(a);
        *(unsigned char*)(b + 0x430) = 0;
        a += 0x48;
        b += 0x48;
    }

    int flags = ((unsigned char*)self)[0];
    flags &= ~0x20;
    ((unsigned char*)self)[0] = (unsigned char)flags;
}
}
