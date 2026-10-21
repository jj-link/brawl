#pragma force_active on
extern void* fn_802552C0(void*, void*, void*, void*, void*);

void* fn_80254830(void* a, void* b, void* c, void* d) {
    if (((unsigned char*)a)[0x6c] != 5) {
        return a;
    }
    return fn_802552C0(a, b, 0, c, d);
}
