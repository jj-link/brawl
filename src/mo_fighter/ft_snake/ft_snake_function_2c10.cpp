#pragma force_active on
extern "C" void* fn_27_1966BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_2C10(void* this_, short flags) {
    if (this_ != 0) {
        fn_27_1966BC(this_, -1);
        if (flags > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
