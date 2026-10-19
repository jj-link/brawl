#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_4B53C(void*, short);
extern "C" void fn_27_19C214(void*, short);

extern "C" void* fn_113_152CC(void* self, short deleting) {
    if (self != 0) {
        fn_27_4B53C(static_cast<unsigned char*>(self) + 0x68, -1);
        fn_27_19C214(self, -1);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
