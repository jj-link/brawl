#pragma force_active on
extern "C" {

extern void __dl__FPv(void*);

void* fn_107_39E0(void* ptr, short destroy) {
    if (ptr != 0 && destroy > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}

}
