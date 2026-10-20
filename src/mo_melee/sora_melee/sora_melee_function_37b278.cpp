#pragma force_active on

extern "C" void* fn_27_B5324(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_37B278(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        fn_27_B5324(static_cast<unsigned char*>(object) + 0x30, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
