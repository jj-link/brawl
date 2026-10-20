#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_123_55DC(void*, short);

extern "C" void* fn_123_5564(void* self, short deleting) {
    if (self != 0) {
        fn_27_1A15B8((unsigned char*)self + 0x470, -1);
        if (self != 0) {
            fn_123_55DC(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
