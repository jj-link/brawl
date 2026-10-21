#pragma force_active on

typedef unsigned int u32;
typedef int s32;
typedef void *voidp;

extern void *fn_80396EEC(void *, void *, int);

void *fn_80397128(void *a, void *b) {
    void *r = fn_80396EEC(a, b, 0);
    if (r != 0) {
        return *(void **)((char *)r + 0x14);
    }
    return b;
}
