#pragma force_active on
extern "C" {
void* fn_27_5BFA0(void*, short);

void* fn_91_87B8(void* object, short deleting) {
    if (object != 0) {
        fn_27_5BFA0(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
