#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_BF70(void*, short);

static inline void destroyPitPoolBase(void* object) {
    if (object != 0) {
        fn_112_BF70(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
    }
}

extern "C" void* fn_112_C030(void* object, short deleting) {
    if (object != 0) {
        destroyPitPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
