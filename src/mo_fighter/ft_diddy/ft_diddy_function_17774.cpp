#pragma force_active on
extern "C" void fn_115_17714(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_17774(void* object, short deleting) {
    if (object != 0) {
        fn_115_17714(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
