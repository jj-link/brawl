#pragma force_active on
extern "C" void fn_93_CFA0(short*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_D000(void* object, short deleting) {
    if (object != 0) {
        fn_93_CFA0(reinterpret_cast<short*>(static_cast<unsigned char*>(object) + 8), -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
