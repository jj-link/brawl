#pragma force_active on
extern "C" void* fn_41_53178(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_53244(void* object, short shouldDelete) {
    if (object != 0) {
        if (object != 0) {
            fn_41_53178(static_cast<char*>(object) + 4, -1);
        }
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
