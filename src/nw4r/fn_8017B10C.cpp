#pragma force_active on
extern "C" void fn_801747D8(void* self);
extern "C" unsigned char lbl_80465530[];

extern "C" void* fn_8017B10C(void* p) {
    fn_801747D8(p);
    *(void**)p = &lbl_80465530;
    return p;
}
