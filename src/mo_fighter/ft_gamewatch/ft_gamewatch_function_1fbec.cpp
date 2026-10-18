#pragma force_active on
extern "C" {

void __dl__FPv(void*);

void* fn_107_1FBEC(void* ptr, short flag) {
    if (ptr != 0 && flag > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}

}
