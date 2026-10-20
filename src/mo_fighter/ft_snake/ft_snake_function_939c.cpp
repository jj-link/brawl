#pragma force_active on
void operator delete(void*);
extern "C" void fn_122_9414(void* object, short flag);
extern "C" void* fn_27_1A15B8(void* object, short flag);

extern "C" void* fn_122_939C(void* self, short deleting) {
    if (self != 0) {
        unsigned char* p = static_cast<unsigned char*>(self);
        fn_27_1A15B8(p + 0x2fc, -1);
        if (self != 0) {
            fn_122_9414(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
