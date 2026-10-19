#pragma force_active on
extern "C" {
void* fn_91_7E48(void*, short);
void* __dl__FPv(void*);

void* fn_91_7EC4(void* object, short deleting) {
    if (object != 0) {
        fn_91_7E48(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
