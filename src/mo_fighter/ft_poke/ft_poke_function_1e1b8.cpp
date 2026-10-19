#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_1E27C(void*, short);

// Nondeleting body: destroys the motion subpool located at +4 of the object.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_116_1E27C(static_cast<unsigned char*>(object) + 4,
                     static_cast<short>(-1));
    }
}

extern "C" void* fn_116_1E1B8(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
