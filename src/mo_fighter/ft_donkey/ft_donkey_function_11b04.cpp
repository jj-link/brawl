#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_399C(void*, short);
extern "C" void* fn_27_1DBB60(void*, short);
extern "C" void* fn_92_11B8C(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_92_11B04(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_92_399C(members + 0x2014, memberDeleting);
        fn_27_1DBB60(members + 0x1FDC, memberDeleting);
        fn_92_11B8C(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
