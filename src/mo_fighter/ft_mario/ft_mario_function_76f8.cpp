#pragma force_active on
extern "C" {
void* fn_27_1A405C(void*, short);

void* fn_91_76F8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A405C(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
