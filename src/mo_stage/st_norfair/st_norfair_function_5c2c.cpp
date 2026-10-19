#pragma force_active on
extern "C" void fn_54_5BEC(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), int, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_54_5C2C(void* object, int freeFlag) {
    if (object != 0) {
        __destroy_arr(static_cast<char*>(object) + 0xC, fn_54_5BEC, 8, 7);
        if (freeFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
