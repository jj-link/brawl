#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_CF9C(void*, short);

// Nondeleting body: destroys the motion subpool at +4 with deleting = -1.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_94_CF9C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
    }
}

extern "C" void* fn_94_D05C(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
