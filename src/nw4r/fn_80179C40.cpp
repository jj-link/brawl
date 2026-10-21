#pragma force_active on
extern "C" {
void fn_801ED0B0(void*, void*, void*);

void* fn_80179C40(void* a, void* b, void* c) {
    fn_801ED0B0(b, c, a);
    return a;
}
}
