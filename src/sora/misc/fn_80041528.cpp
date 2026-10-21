#pragma force_active on
extern "C" void* fn_8004231C(void*, void*);

extern "C" void* fn_80041528(void* a, void* b) {
    return fn_8004231C(b, a);
}
