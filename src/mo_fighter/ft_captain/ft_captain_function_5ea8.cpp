#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_689B0(void*, short);
void fn_27_1985B4(void*, short);
}

extern "C" void* fn_100_5EA8(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        fn_27_689B0(static_cast<char*>(object) + 0x7c, destroy);
        if (object != 0) {
            fn_27_1985B4(object, destroy);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
