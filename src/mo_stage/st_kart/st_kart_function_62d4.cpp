#pragma force_active on
typedef void (*Destructor)(void*, int);

extern "C" void* fn_49_622C(void*, int);
extern "C" void __destroy_arr(void*, Destructor, unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_49_62D4(void* object, int release) {
    if (object != 0) {
        __destroy_arr((char*)object + 0xC, (Destructor)fn_49_622C, 8, 6);
        if (release > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
