#pragma force_active on
extern "C" void fn_110_1E960(void*, short);

static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_110_1E960(static_cast<unsigned char*>(object) + 4,
                     static_cast<short>(-1));
    }
}

extern "C" void* fn_110_1E89C(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
