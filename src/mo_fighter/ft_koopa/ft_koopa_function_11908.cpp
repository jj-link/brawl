#pragma force_active on
void operator delete(void*);
extern "C" void fn_102_119CC(void*, short);

static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_102_119CC(static_cast<unsigned char*>(object) + 4,
                     static_cast<short>(-1));
    }
}

extern "C" void* fn_102_11908(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
