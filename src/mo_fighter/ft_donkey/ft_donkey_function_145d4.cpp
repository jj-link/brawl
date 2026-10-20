#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_399C(void*, short);
extern "C" void* fn_27_1DBB60(void*, short);
extern "C" void* fn_92_1465C(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_92_145D4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_92_399C(members + 0x1F48, memberDeleting);
        fn_27_1DBB60(members + 0x1F10, memberDeleting);
        fn_92_1465C(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
