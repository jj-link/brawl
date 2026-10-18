#pragma force_active on
extern "C" void* fn_121_D784(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_D7E4(void* object, short deleting) {
    if (object != 0) {
        fn_121_D784(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
