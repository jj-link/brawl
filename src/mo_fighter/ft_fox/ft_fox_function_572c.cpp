#pragma force_active on
void operator delete(void*);
extern "C" void fn_97_57F0(void*, short);

// Nondeleting body: its motion subpool starts at +4.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_97_57F0(static_cast<unsigned char*>(object) + 4,
                   static_cast<short>(-1));
    }
}

extern "C" void* fn_97_572C(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
