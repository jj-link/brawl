#pragma force_active on
extern "C" void* fn_99_A588(void*, short);

extern "C" void* fn_99_A5E8(void* object, short deleting) {
    if (object) {
        fn_99_A588(static_cast<unsigned char*>(object) + 0x8, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
