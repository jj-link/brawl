#pragma force_active on
extern "C" void* fn_117_34A0(void*, short);
extern "C" void* fn_117_3500(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_3434(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_34A0(storage + 0x1EE0, memberDeleting);
        fn_117_3500(storage + 4, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
