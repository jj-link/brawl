#pragma force_active on
typedef void (*VFn)(void*, void*);

typedef struct Obj {
    char pad[0xC];
    VFn fn;
} Obj;

extern Obj* lbl_805A0D18;
void fn_8022F0E0(void*);

void fn_80231844(short* a, short b)
{
    *a = b;
    if (lbl_805A0D18 != 0) {
        lbl_805A0D18->fn(a, lbl_805A0D18);
    } else {
        fn_8022F0E0(a);
    }
}
