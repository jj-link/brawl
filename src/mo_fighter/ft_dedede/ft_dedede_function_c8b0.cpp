void operator delete(void*);
extern "C" void* fn_117_A614(void*, short);

// Nondeleting base lifetime operation on the unchanged receiver. The stop-energy
// holder calls this destructor at +4; the complete receiver layout stays opaque.
static inline void destroyStopEnergyBase(void* object) {
    if (object != 0) {
        fn_117_A614(object, static_cast<short>(0));
    }
}

extern "C" void* fn_117_C8B0(void* object, short deleting) {
    if (object != 0) {
        destroyStopEnergyBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
