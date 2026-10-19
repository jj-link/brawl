#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_126_1E9C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_126_2754(void*, short);
}

extern "C" void* fn_126_1E20(void* self, short deleting) {
    unsigned char* members = reinterpret_cast<unsigned char*>(self);
    short memberDeleting = -1;
    if (self != 0) {
        fn_126_1E9C(members + 0x6458, memberDeleting);
        fn_27_C74E8(members + 0x6448, memberDeleting);
        fn_126_2754(self, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
