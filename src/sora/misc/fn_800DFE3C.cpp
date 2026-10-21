#pragma force_active on
extern "C" {
void fn_8007266C(void*);

void* fn_800DFE3C(void* p) {
    fn_8007266C(p);
    return p;
}
}
