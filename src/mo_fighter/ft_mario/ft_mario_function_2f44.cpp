#pragma force_active on
extern "C" {
void* fn_27_22A38(void*, short);
void* fn_27_1A2910(void*, short);
void __dl__FPv(void*);

void* fn_91_2F44(void* object, short deleting) {
    if (object != 0) {
        fn_27_22A38(static_cast<unsigned char*>(object) + 0x34, static_cast<short>(-1));
        fn_27_1A2910(object, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
