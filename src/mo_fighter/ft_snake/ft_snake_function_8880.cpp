#pragma force_active on
extern "C" void operator delete(void*);
extern "C" void* fn_122_8944(void*, short);

static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_122_8944(static_cast<unsigned char*>(object) + 4,
                    static_cast<short>(-1));
    }
}

extern "C" void* fn_122_8880(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
