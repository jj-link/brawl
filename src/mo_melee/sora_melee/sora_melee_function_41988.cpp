#pragma force_active on
extern "C" {
typedef void (*Dtor)(void*, int);
void __destroy_arr(void*, Dtor, unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__8clTargetFv(void*, int);

void* fn_27_41988(void* object, int shouldDelete) {
    if (object) {
        __destroy_arr((char*)object + 12, __dt__8clTargetFv, 8, 6);
        if (shouldDelete > 0)
            __dl__FPv(object);
    }
    return object;
}
}
