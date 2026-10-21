#pragma force_active on
extern "C" {
void fn_800429C8(void*);

void* fn_80042998(void* p) {
    fn_800429C8(p);
    return p;
}
}
