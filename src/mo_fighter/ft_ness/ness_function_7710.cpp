#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_7770(void*, short);

struct NessSupportBase {
    inline ~NessSupportBase() {
        fn_101_7770(this, static_cast<short>(0));
    }
};

extern "C" NessSupportBase* fn_101_7710(NessSupportBase* object, short deleting) {
    if (object != 0) {
        object->~NessSupportBase();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
