#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_614C4(void*, short);
void* fn_27_D3080(void*, short);
}

struct NessCompositeBase {
    inline ~NessCompositeBase() {
        fn_27_D3080(this, static_cast<short>(-1));
    }
};

extern "C" void* fn_101_8694(void* object, short deleting) {
    if (object != 0) {
        fn_27_614C4(static_cast<unsigned char*>(object) + 0xAC, static_cast<short>(-1));
        static_cast<NessCompositeBase*>(object)->~NessCompositeBase();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
