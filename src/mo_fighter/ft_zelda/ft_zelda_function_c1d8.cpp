#pragma force_active on
void operator delete(void*);
extern "C" void fn_104_C118(void*, short);

// Nondeleting body: destroys the motion subpool at +4 when the object is non-null.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_104_C118(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
    }
}

extern "C" void* fn_104_C1D8(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
