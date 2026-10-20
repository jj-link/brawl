#pragma force_active on
void operator delete(void*);
extern "C" void fn_96_57E8(void*, short);
extern "C" void* fn_27_1A1CFC(void*, short);

extern "C" void* fn_96_5860(void* self, short deleting) {
    if (self != 0) {
        unsigned char* storage = static_cast<unsigned char*>(self);
        fn_27_1A1CFC(storage + 0x524, -1);
        if (self != 0) {
            fn_96_57E8(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
