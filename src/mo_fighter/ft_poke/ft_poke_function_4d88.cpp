#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_4E4C(void*, short);

// Nondeleting body of the ft_poke instance lifetime operation at 4D88.
// Its motion subpool starts at +4; the complete receiver layout stays opaque.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_116_4E4C(static_cast<unsigned char*>(object) + 4,
                    static_cast<short>(-1));
    }
}

extern "C" void* fn_116_4D88(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
