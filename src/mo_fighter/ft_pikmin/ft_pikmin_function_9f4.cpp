#pragma force_active on
extern "C" void* fn_113_A6C(void*, short);
extern "C" void fn_113_AC8(void*, short);
extern "C" void* fn_113_B24(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_9F4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = 0;
        fn_113_A6C(storage + 0x20, destroyMember);
        fn_113_AC8(storage + 0x14, destroyMember);
        fn_113_B24(storage + 8, destroyMember);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
