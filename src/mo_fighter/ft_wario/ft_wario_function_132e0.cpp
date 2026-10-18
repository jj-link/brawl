#pragma force_active on
void operator delete(void*);

extern "C" void fn_110_AAD8(void*, short);

extern "C" void* fn_110_132E0(void* object, short deleting) {
    if (object != 0) {
        fn_110_AAD8(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
