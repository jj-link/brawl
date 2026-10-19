#pragma force_active on
void operator delete(void*);
extern "C" void fn_93_CE20(void*, short);

// Destroys the motion subpool at +4 (nondeleting path), then frees the object
// if the deleting flag is positive.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_93_CE20(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
    }
}

extern "C" void* fn_93_CEE0(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
