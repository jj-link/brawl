#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_125_42F0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_125_4264(void* object, short deleting) {
    if (object != 0) {
        fn_27_B5324(static_cast<unsigned char*>(object) + 0x20, -1);
        unsigned char* ptr = static_cast<unsigned char*>(object) + 0x10;
        if (ptr != 0) {
            fn_125_42F0(ptr, 0);
        }
        if (object != 0) {
            fn_125_42F0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
