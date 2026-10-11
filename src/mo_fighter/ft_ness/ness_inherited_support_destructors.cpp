void operator delete(void*);
extern "C" void* fn_101_3B0C(void*, short);

struct NessSupportBase {
    inline ~NessSupportBase() {
        fn_101_3B0C(this, static_cast<short>(0));
    }
};

extern "C" void* fn_101_155C4(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" NessSupportBase* fn_101_15604(NessSupportBase* object, short deleting) {
    if (object != 0) {
        object->~NessSupportBase();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
