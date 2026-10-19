#pragma force_active on
extern "C" {

void __dl__FPv(void*);

void* fn_27_D21F0(void* ptr, int size) {
    if (ptr && size > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}

}
