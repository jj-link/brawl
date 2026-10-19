#pragma force_active on
extern "C" {

void fn_123_C224(void* p, short flags);
void __dl__FPv(void* p);

void* fn_123_C29C(void* this_, short flags) {
    if (this_ != 0) {
        fn_123_C224(this_, 0);
        if (flags > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
