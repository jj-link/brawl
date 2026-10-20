#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_105_36B4(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_105_206B0(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_105_20628(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_105_36B4(members + 0x1FA8, memberDeleting);
        fn_27_1DBB60(members + 0x1F70, memberDeleting);
        fn_105_206B0(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
