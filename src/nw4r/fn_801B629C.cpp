#pragma force_active on
extern "C" {
extern void* fn_801F22CC(void*, void*, void*, void*);

void* fn_801B629C(void* a, void* b) {
    if (b == 0) {
        return a;
    }
    return fn_801F22CC((char*)a + 4, b, (char*)b + 4, (char*)b + 8);
}
}
