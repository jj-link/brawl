#pragma force_active on
extern "C" void* fn_99_A528(void*, short);

extern "C" void* fn_99_A588(void* object, short deleting) {
    if (object) {
        fn_99_A528(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
