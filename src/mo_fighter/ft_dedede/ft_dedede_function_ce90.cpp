void operator delete(void*);
extern "C" void* fn_117_CE30(void*, short);
extern "C" void* fn_117_CCFC(void*, short);

// Destroy the observed base subobject without releasing its storage.
static inline void destroyBase(void* object) {
    if (object != 0) {
        fn_117_CCFC(object, static_cast<short>(0));
    }
}

extern "C" void* fn_117_CE90(void* object, short deleting) {
    if (object != 0) {
        fn_117_CE30(static_cast<unsigned char*>(object) + 0x1c8,
                    static_cast<short>(-1));
        destroyBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
