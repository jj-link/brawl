#pragma force_active on
void operator delete(void*);
extern "C" void fn_105_5FD0(void*, short);

// Nondeleting body: destroys the motion subpool located at +4 of the object.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_105_5FD0(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
    }
}

extern "C" void* fn_105_5F0C(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
