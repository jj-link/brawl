#include <revolution/OS/OSMutex.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0(int);
};
struct Object_vptr_8_base { char pad[8]; };
class Object_vptr_8 : public Object_vptr_8_base {
public:
    virtual void slot0(int);
};
struct Owner {
    char pad[0x5d0];
    Object_vptr_8* a;
    Object_vptr_0* b;
    Object_vptr_0* c;
    Object_vptr_0* d;
    Object_vptr_0* e;
    void* f;
};
extern OSMutex lbl_80532170;
extern "C" {
void fn_801BED78(void*);
void fn_801C0DBC(void*);
void fn_801C21F8(void*);
void fn_801CA8F8(void*);
void fn_801C8C14(void*);
void fn_801CA7E8(void*);
}
inline void cleanup(void* p) {
    if (p) fn_801CA7E8(p);
}
extern "C" void fn_802789B4(Owner* self) {
    OSMutex* mutex = &lbl_80532170;
    OSLockMutex(mutex);
    if (self->b) {
        fn_801BED78(self->b);
        self->b->slot0(-1);
    }
    if (self->c) {
        fn_801C0DBC(self->c);
        self->c->slot0(-1);
    }
    if (self->d) {
        fn_801C21F8(self->d);
        self->d->slot0(-1);
    }
    if (self->e) {
        fn_801CA8F8(self->e);
        self->e->slot0(-1);
    }
    if (self->a) {
        fn_801C8C14(self->a);
        self->a->slot0(-1);
    }
    if (self->f) cleanup(self->f);
    OSUnlockMutex(mutex);
}
