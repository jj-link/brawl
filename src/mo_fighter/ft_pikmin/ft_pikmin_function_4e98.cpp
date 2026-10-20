#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1FE4(void*, short);
extern "C" void fn_113_4F10(void*, short);

extern "C" void* fn_113_4E98(void* self, short deleting) {
    if (self != 0) {
        fn_27_1A1FE4((unsigned char*)self + 0x244, -1);
        if (self != 0) {
            fn_113_4F10(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
