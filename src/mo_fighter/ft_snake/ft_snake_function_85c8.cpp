#pragma force_active on
extern "C" void* fn_122_8628(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_122_85C8(void* object, short deleting) {
    if (object != 0) {
        fn_122_8628(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
