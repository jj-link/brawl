void operator delete(void*);
extern "C" void* fn_117_CC9C(void*, short);
extern "C" void* fn_117_CB64(void*, short);

// The damage-energy pool base is destroyed without deleting its storage.
// Keep the observed base lifetime operation opaque; no full layout is assumed.
static inline void destroyKineticPoolBase(void* object) {
    if (object != 0) {
        fn_117_CB64(object, static_cast<short>(0));
    }
}

extern "C" void* fn_117_CCFC(void* object, short deleting) {
    if (object != 0) {
        fn_117_CC9C(static_cast<unsigned char*>(object) + 0x17C,
                    static_cast<short>(-1));
        destroyKineticPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
