#pragma force_active on
extern "C" {
void* fn_98_14878(void* storage);
void fn_98_1472C(void* storage, int arg);

void fn_98_146E8(void* storage) {
    fn_98_1472C(storage, 0);
    void* next = fn_98_14878(storage);
    if (next) {
        fn_98_146E8(next);
    }
}
}
