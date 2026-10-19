#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_CA0C(void*, short);

// Nondeleting body of the pool lifetime operation at CACC.
// Its pool base starts at +4.
static inline void destroyPoolBase(void* object) {
    if (object != 0) {
        fn_125_CA0C(static_cast<unsigned char*>(object) + 4,
                    static_cast<short>(-1));
    }
}

extern "C" void* fn_125_CACC(void* object, short deleting) {
    if (object != 0) {
        destroyPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
