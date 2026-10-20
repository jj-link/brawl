#pragma force_active on
extern "C" {
void* fn_120_11F04(void* self, short flags);
void* fn_27_1DBB60(void*, short);
void* fn_120_17E60(void* object, short deleting);
void* fn_27_1D81C8(void* self, short flag);
void __dl__FPv(void*);
}

void operator delete(void*);

extern "C" void* fn_120_17ED0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_120_11F04(members + 0x21C4, memberDeleting);
        fn_27_1DBB60(members + 0x218C, memberDeleting);
        fn_120_17E60(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
