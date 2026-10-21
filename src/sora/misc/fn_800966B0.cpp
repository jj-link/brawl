#pragma force_active on
extern "C" {

void fn_801EC1B8(void* a, void* b, void* c);

void* fn_800966B0(void* a, void* b, void* c) {
    fn_801EC1B8(b, c, a);
    return a;
}

}
