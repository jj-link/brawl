#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_1A15B8(void*, short);
void* fn_101_7950(void*, short);
}

extern "C" void* fn_101_78D8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x470, static_cast<short>(-1));
        void* self = object;
        if (self != 0) {
            fn_101_7950(self, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
