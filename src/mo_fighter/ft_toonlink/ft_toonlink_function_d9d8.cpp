#pragma force_active on
extern "C" void* fn_121_D978(void*, short);
extern "C" void* fn_121_D844(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_D9D8(void* object, short deleting) {
    if (object != 0) {
        fn_121_D978(static_cast<unsigned char*>(object) + 0x204, -1);
        if (object != 0) {
            fn_121_D844(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
