#pragma force_active on
extern "C" void* fn_99_9DB4(void*, short);

extern "C" void* fn_99_9E74(void* object, short deleting) {
    if (object) {
        if (object) {
            fn_99_9DB4(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
