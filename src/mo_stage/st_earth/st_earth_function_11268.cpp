#pragma force_active on
typedef void (*Dtor)(void*, int);

extern "C" {
void __destroy_arr(void*, Dtor, unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__18soCollisionHitPartFv(void*, int);
}

extern "C" void* fn_66_11268(void* ptr, int flags) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xc, __dt__18soCollisionHitPartFv, 0x68, 2);
        if (flags > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
