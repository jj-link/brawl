#pragma force_active on
typedef struct Elem {
    int a;
    int b;
    int c;
} Elem;

typedef struct Obj {
    char pad[0x18];
    int flags;
    Elem elems[4];
} Obj;

extern "C" Elem* fn_27_F4888(Obj* self, int idx)
{
    int n = (self->flags >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return &self->elems[n];
}
