#pragma force_active on
extern "C" {
void* fn_27_63EBC(void*, short);

void* fn_91_6308(void* object, short deleting) {
    if (object != 0) {
        fn_27_63EBC(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
