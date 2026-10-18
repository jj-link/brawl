#pragma force_active on
extern "C" void fn_99_A8B0(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_99_A910(void* object, short deleting) {
    if (object) {
        fn_99_A8B0(static_cast<unsigned char*>(object) + 0x8, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
