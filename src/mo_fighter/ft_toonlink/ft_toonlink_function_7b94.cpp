#pragma force_active on
extern "C" void* fn_121_79F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_7B94(void* object, short deleting) {
    if (object != 0) {
        fn_121_79F0(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
