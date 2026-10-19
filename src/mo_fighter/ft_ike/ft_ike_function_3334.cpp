#pragma force_active on
extern "C" void* fn_119_33F8(void* object, short deleting);
extern "C" void __dl__FPv(void*);

static inline void destroyBase(void* object) {
    if (object != 0) {
        fn_119_33F8(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
    }
}

extern "C" void* fn_119_3334(void* object, short deleting) {
    if (object != 0) {
        destroyBase(object);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
