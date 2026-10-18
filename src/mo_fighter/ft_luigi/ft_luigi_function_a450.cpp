#pragma force_active on
extern "C" void fn_99_A3F0(void*, short);

extern "C" void* fn_99_A450(void* object, short deleting) {
    if (object) {
        fn_99_A3F0(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
