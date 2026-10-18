#pragma force_active on
extern "C" void* fn_121_2CA0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_2CE0(void* object, short deleting) {
    if (object != 0) {
        fn_121_2CA0(static_cast<unsigned char*>(object) + 12, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
