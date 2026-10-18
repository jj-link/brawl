#pragma force_active on
extern "C" {
void fn_100_B458(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_B4B4(void* object, short refCount) {
    if (object != 0) {
        fn_100_B458(static_cast<char*>(object) + 4, -1);
        if (refCount > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
