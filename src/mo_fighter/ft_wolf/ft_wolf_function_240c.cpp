#pragma force_active on
extern "C" void* fn_125_220C(void*, short);
extern "C" void* fn_125_22A8(void*, short);
extern "C" void* fn_125_22E8(void*, short);
extern "C" void* fn_27_C7770(void*, short);

void operator delete(void*);

extern "C" void* fn_125_240C(void* self, short deleting) {
    if (self != 0) {
        unsigned char* members = static_cast<unsigned char*>(self);
        short memberDeleting = -1;
        fn_125_220C(members + 0xdc, memberDeleting);
        fn_125_22A8(members + 0xc0, memberDeleting);
        fn_125_22E8(members + 0x14, memberDeleting);
        if (self != 0) {
            fn_27_C7770(self, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
