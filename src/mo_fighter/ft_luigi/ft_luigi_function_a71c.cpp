#pragma force_active on
extern "C" void fn_99_A6C0(void*, short);
extern "C" void* __dl__FPv(void*);

extern "C" void* fn_99_A71C(void* object, short deleting) {
    if (object) {
        fn_99_A6C0(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
