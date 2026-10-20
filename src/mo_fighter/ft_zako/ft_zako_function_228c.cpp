#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_126_2000(void*, short);
void* fn_126_209C(void*, short);
void* fn_126_20DC(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_126_228C(void* self, short deleting) {
    if (self != 0) {
        short memberDeleting = -1;
        fn_126_2000(static_cast<unsigned char*>(self) + 0xDC, memberDeleting);
        fn_126_209C(static_cast<unsigned char*>(self) + 0xC0, memberDeleting);
        fn_126_20DC(static_cast<unsigned char*>(self) + 0x14, memberDeleting);
        if (self != 0) {
            fn_27_C7770(self, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
