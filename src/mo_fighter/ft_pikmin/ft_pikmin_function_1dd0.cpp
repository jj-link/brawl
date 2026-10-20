#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_113_1E58(void*, short);
void* fn_27_CDBBC(void*, short);
void* fn_27_D36DC(void*, short);

void* fn_113_1DD0(void* self, short deleting) {
    if (self != 0) {
        fn_27_93100(static_cast<unsigned char*>(self) + 0x1783C, static_cast<short>(-1));
        fn_113_1E58(static_cast<unsigned char*>(self) + 0xE0, static_cast<short>(-1));
        fn_27_CDBBC(static_cast<unsigned char*>(self) + 0x34, static_cast<short>(-1));
        fn_27_D36DC(self, static_cast<short>(-1));
        if (deleting > 0) operator delete(self);
    }
    return self;
}
}
