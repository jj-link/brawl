#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_3B0C(void*, short);

struct NessSupportBase {
    inline ~NessSupportBase() {
        fn_101_3B0C(this, static_cast<short>(0));
    }
};

extern "C" void* fn_101_1C1C0(void* object, short deleting) {
    if (object != 0) {
        static_cast<NessSupportBase*>(object)->~NessSupportBase();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
