#pragma force_active on
void operator delete(void*);
extern "C" void fn_120_B0F0(void*, short);

// Nondeleting body: destroys the motion subpool at +4 when the object is non-null.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_120_B0F0(static_cast<unsigned char*>(object) + 4,
                    static_cast<short>(-1));
    }
}

extern "C" void* fn_120_B1B0(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
