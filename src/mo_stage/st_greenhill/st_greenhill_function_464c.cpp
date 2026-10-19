#pragma force_active on
typedef void (*Destructor)(void*, int);

extern "C" void __destroy_arr(void*, Destructor, int, int);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_72_460C(void*, int);

extern "C" void* fn_72_464C(void* object, int shouldDelete) {
    if (object != 0) {
        __destroy_arr((void*)((char*)object + 0xC),
                      (Destructor)fn_72_460C, 8, 7);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
