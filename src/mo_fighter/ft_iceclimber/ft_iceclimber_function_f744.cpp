#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_F684(void*, short);

// Nondeleting body of the instance-pool lifetime operation at F744.
// Its motion subpool starts at +4.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_105_F684(static_cast<unsigned char*>(object) + 4,
                    static_cast<short>(-1));
    }
}

extern "C" void* fn_105_F744(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
