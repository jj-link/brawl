#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A1FE4(void*, short);
extern "C" void fn_95_69B4(void*, short);

extern "C" void* fn_95_693C(void* self, short deleting) {
    if (self != 0) {
        fn_27_1A1FE4((unsigned char*)self + 0x244, -1);
        if (self != 0) {
            fn_95_69B4(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
