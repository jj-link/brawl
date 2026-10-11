extern "C" {
void* fn_98_17D34(void* owner);
void fn_98_149B8(void* storage);
void fn_98_146E8(void* storage);
void fn_98_1829C(void* owner);

void fn_98_17AF0(void* owner) {
    void* storage = fn_98_17D34(owner);
    if (storage) {
        fn_98_149B8(storage);
    }
    storage = fn_98_17D34(owner);
    if (storage) {
        fn_98_146E8(storage);
    }
    fn_98_1829C(owner);
}
}
