#pragma force_active on
void operator delete(void*);
extern "C" void fn_112_E798(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_112_E728(void* self, short deleting) {
    if (self != 0) {
        fn_112_E798(static_cast<unsigned char*>(self) + 0xCC, -1);
        fn_27_1D81C8(self, 0);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
