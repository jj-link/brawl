#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_2219C(void*, short);

// Nondeleting body of the instance lifetime operation at 220D8.
// Its motion subpool starts at +4.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_122_2219C(static_cast<unsigned char*>(object) + 4,
                     static_cast<short>(-1));
    }
}

extern "C" void* fn_122_220D8(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
