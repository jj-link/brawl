void operator delete(void*);
extern "C" void* fn_117_C7D8(void*, short);
extern "C" void* fn_117_C6A8(void*, short);

// The gravity/motion pool base is destroyed without deleting its storage.
// Keep the observed base lifetime operation opaque; no full layout is assumed.
static inline void destroyKineticPoolBase(void* object) {
    if (object != 0) {
        fn_117_C6A8(object, static_cast<short>(0));
    }
}

extern "C" void* fn_117_C838(void* object, short deleting) {
    if (object != 0) {
        fn_117_C7D8(static_cast<unsigned char*>(object) + 0x94,
                    static_cast<short>(-1));
        destroyKineticPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
