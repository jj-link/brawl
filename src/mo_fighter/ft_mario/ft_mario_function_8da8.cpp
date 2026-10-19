#pragma force_active on
extern "C" {
void* fn_27_1A5AC4(void*, short);

void* fn_91_8DA8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A5AC4(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
