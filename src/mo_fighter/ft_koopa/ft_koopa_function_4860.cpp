#pragma force_active on
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_102_48D8(void*, short);

void operator delete(void*);

extern "C" void* fn_102_4860(void* self, short deleting) {
    if (self != 0) {
        unsigned char* storage = static_cast<unsigned char*>(self);
        fn_27_1A18A0(storage + 0x354, -1);
        if (self != 0) {
            fn_102_48D8(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
