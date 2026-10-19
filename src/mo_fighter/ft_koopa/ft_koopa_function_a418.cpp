#pragma force_active on
extern "C" void* fn_102_A358(void*, short);

static inline void destroyBase(void* object) {
    if (object != 0) {
        fn_102_A358(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
    }
}

extern "C" void* fn_102_A418(void* object, short deleting) {
    if (object != 0) {
        destroyBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
