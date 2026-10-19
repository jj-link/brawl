#pragma force_active on
extern "C" {
void fn_126_1980(void*, short);
void __dl__FPv(void*);
void* fn_126_1B54(void* ptr, short count);
}

void* fn_126_1B54(void* ptr, short count) {
    void* r30 = ptr;
    short r31 = count;
    if (r30 != 0) {
        fn_126_1980(r30, 0);
        if (r31 > 0) {
            __dl__FPv(r30);
        }
    }
    return r30;
}
