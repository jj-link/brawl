#pragma force_active on
extern "C" void* fn_99_2284(void*, short);
extern "C" void* fn_99_20E0(void*, short);

extern "C" void* fn_99_2218(void* object, short deleting) {
    if (object) {
        short destroyComponent = -1;
        fn_99_2284(static_cast<unsigned char*>(object) + 0x50, destroyComponent);
        fn_99_20E0(object, destroyComponent);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
