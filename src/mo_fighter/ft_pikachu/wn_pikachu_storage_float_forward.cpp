extern "C" {
void* fn_98_17D34(void* owner);
void fn_98_14A18(void* storage, float value);

void fn_98_1856C(void* owner, float value) {
    void* storage = fn_98_17D34(owner);
    if (storage) {
        fn_98_14A18(storage, value);
    }
}
}
