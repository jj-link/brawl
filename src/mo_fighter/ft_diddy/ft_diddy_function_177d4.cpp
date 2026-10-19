#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_17714(void*, short);

// Nondeleting body of the instance lifetime operation at 177D4.
// Its motion subpool starts at +4; the complete receiver layout stays opaque.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_115_17714(static_cast<unsigned char*>(object) + 4,
                     static_cast<short>(-1));
    }
}

extern "C" void* fn_115_177D4(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
