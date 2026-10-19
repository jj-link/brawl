#pragma force_active on
void operator delete(void*);
extern "C" void* fn_117_3B14(void*, short);

static inline void destroyBase(void* object) {
    if (object != 0) {
        fn_117_3B14(static_cast<unsigned char*>(object) + 4, -1);
    }
}

extern "C" void* fn_117_3A50(void* object, short deleting) {
    if (object != 0) {
        destroyBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
