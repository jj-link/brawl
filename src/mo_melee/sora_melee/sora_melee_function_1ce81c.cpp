#pragma force_active on
typedef int s32;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Elem;

typedef struct {
    char pad[0x18];
    s32 idx;
    Elem arr[32];
} Obj;

extern "C" Elem* fn_27_1CE81C(Obj* o, s32 i)
{
    s32 n = (o->idx >> 25) + i;
    if (n >= 32) {
        n -= 32;
    }
    return &o->arr[n];
}
