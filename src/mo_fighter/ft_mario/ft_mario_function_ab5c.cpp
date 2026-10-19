#pragma force_active on
extern "C" {
void* fn_91_AA30(void*, void*, void*);

void* fn_91_AB5C(void* a, void* b) {
    char result[16];
    fn_91_AA30(result, a, b);
    return result;
}
}
