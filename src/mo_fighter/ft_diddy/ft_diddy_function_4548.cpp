#pragma force_active on
void operator delete(void*);
extern "C" void fn_115_460C(void*, short);

static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_115_460C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
    }
}

extern "C" void* fn_115_4548(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
