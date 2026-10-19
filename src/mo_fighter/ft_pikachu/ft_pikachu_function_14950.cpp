#pragma force_active on
extern "C" {
void* fn_98_14878(void*);
int fn_98_14854(void*, int);
void fn_98_14774(void*, void*);
}

extern "C" void fn_98_14950(void* owner, int a) {
    void* result = fn_98_14878(owner);
    if (result) {
        fn_98_14950(result, a);
    } else {
        fn_98_14854(owner, a);
        fn_98_14774(owner, result);
    }
}
