#pragma force_active on
extern "C" void* fn_112_455C(void* object, short deleting);
extern "C" void* fn_112_45C8(void* object, short deleting);
extern "C" void* fn_112_4654(void* object, short deleting);
extern "C" void* fn_112_46E0(void* object, short deleting);
extern "C" void* fn_112_E898(void* object, short deleting);

extern "C" void* fn_112_E808(void* object, short deleting) {
    if (object != 0) {
        fn_112_455C(static_cast<char*>(object) + 0x4B0, -1);
        fn_112_45C8(static_cast<char*>(object) + 0x384, -1);
        fn_112_4654(static_cast<char*>(object) + 0x258, -1);
        fn_112_46E0(static_cast<char*>(object) + 0x12C, -1);
        fn_112_E898(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
