#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_12054(void*, short);

// Nondeleting body of the observed instance-pool lifetime operation at 12114.
// Its motion subpool starts at +4; the complete receiver layout stays opaque.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_122_12054(static_cast<unsigned char*>(object) + 4,
                     static_cast<short>(-1));
    }
}

extern "C" void* fn_122_12114(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
