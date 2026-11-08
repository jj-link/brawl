#include <types.h>
#pragma force_active on
class Class_80488D40 {
public:
    virtual void fn_8032BD00();
    virtual void fn_80080A64();
    virtual void fn_8032BC08();
    virtual void fn_8032BD6C();
    u32 pad;
    u32 size;
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual u32 slot3(u32);
    u32 pad[3];
    u32 current;
    u32 pad2[2];
    u32 end;
};
struct Result { u32 a, b, c, d, e, f, ptr, size; };
extern "C" u32 fn_8032BD5C(Class_80488D40*, void*, void*, Result*);
extern "C" Object_vptr_0* lbl_805A0EC8;
extern "C" int fn_8032BC08(Class_80488D40* self, void* a, void* b, Result* out) {
    int v = (signed char)(fn_8032BD5C(self, a, b, out) >> 24);
    if (((u32)(-v | v) >> 31) != 0) {
        u32 size = self->size;
        out->size = size;
        u32 aligned = (size + 16) & ~15;
        Object_vptr_0* heap = lbl_805A0EC8;
        u32 ptr = heap->current;
        u32 next = ptr + aligned;
        if (next <= heap->end) heap->current = next;
        else ptr = heap->slot3(aligned);
        out->ptr = ptr;
        out->e = 3;
        out->f = 4;
        out->c = 1000;
        out->d = 1000;
        out->b = 1000;
        out->a = 2;
        return 0;
    }
    return 1;
}