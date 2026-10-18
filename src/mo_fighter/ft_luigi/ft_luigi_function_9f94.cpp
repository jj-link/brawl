#pragma force_active on
extern "C" void* fn_99_9F34(void*, short);
extern "C" void* __dl__FPv(void*);

extern "C" void* fn_99_9F94(void* object, short deleting) {
    if (object) {
        fn_99_9F34(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
