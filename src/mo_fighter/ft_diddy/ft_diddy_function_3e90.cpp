#pragma force_active on
extern "C" void fn_115_3F0C(void* object, short deleting);
extern "C" void fn_115_4038(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_115_3E90(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_3F0C(storage + 0x15D04, -1);

        if (object != 0) {
            fn_115_4038(object, 0);
        }

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
