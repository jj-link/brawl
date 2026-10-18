#pragma force_active on
extern "C" void* fn_93_D72C(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_93_D788(void* object, short deleting) {
    if (object != 0) {
        fn_93_D72C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
