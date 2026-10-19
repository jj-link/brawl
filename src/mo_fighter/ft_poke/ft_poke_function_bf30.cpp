#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_BE70(void*, short);

// Nondeleting body of the ft_poke instance-pool lifetime operation at BF30.
// Its motion subpool starts at +4.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_116_BE70(static_cast<unsigned char*>(object) + 4,
                    static_cast<short>(-1));
    }
}

extern "C" void* fn_116_BF30(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
