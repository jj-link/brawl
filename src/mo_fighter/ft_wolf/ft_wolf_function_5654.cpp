#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_5718(void*, short);

static inline void destroyMotionPoolBase(void* object) {
    if (object != 0) {
        fn_125_5718(static_cast<unsigned char*>(object) + 4,
                    static_cast<short>(-1));
    }
}

extern "C" void* fn_125_5654(void* object, short deleting) {
    if (object != 0) {
        destroyMotionPoolBase(object);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
