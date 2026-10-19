#pragma force_active on
void operator delete(void*);
extern "C" void fn_93_174BC(void*, short);

// Nondeleting body: destroys the motion subpool at +4, then the object itself if deleting > 0.
static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_93_174BC(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
    }
}

extern "C" void* fn_93_173F8(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
