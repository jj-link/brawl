#pragma force_active on
struct Inner {
    char pad[0x10];
    void* data;
};

struct Outer {
    void* unknown;
    Inner* inner;
};

struct Work {
    char data[0x18];
};

extern "C" void* fn_801C6B78(void*);
extern "C" void* fn_801C9804(Inner*, int);
extern "C" void fn_801D3C8C(Work*, int);
extern "C" int fn_801D3D08(Work*, void*, int);
extern "C" int fn_801D3E28(Work*, int*, int, int);
extern "C" int fn_801D3F38(Work*, int, int, void*);

extern "C" int fn_801CA5AC(
    Outer* self, void* a, int* b, int c, int d, int e, int f, int g
) {
    void* p = self->inner->data;
    if (p == 0)
        p = 0;
    else
        p = fn_801C6B78(p);

    if (p == 0)
        return 0;

    void* result = fn_801C9804(self->inner, g);
    if (result == 0)
        return 0;

    Work work;
    fn_801D3C8C(&work, d);

    if (fn_801D3D08(&work, a, e) == 0)
        return 0;

    if (fn_801D3E28(&work, b, e, f) == 0)
        return 0;

    return fn_801D3F38(&work, *b, c, result);
}
