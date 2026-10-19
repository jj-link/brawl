#pragma force_active on
extern "C" {
void* fn_27_1966BC(void*, short);
void* __dl__FPv(void*);

void* fn_91_875C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1966BC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
