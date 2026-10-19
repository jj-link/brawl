#pragma force_active on
extern "C" {
void fn_95_1C58(void*, short);
void __dl__FPv(void*);

void* fn_95_1DD0(void* ptr, int flag) {
    if (ptr) {
        fn_95_1C58(ptr, 0);
        if ((short)flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
}
