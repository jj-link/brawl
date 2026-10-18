#pragma force_active on
extern "C" void* fn_114_3FE4(void*, short);
extern "C" void* fn_114_4068(void*, short);
extern "C" void* fn_114_5A38(void*, short);
extern "C" void* fn_114_40C8(void*, short);
extern "C" void* fn_114_188B8(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_114_1881C(void* self, short flag) {
    if (self) {
        fn_114_3FE4((char*)self + 0x118, (short)-1);
        fn_114_4068((char*)self + 0x104, (short)-1);
        fn_114_5A38((char*)self + 0xF4, (short)-1);
        fn_114_40C8((char*)self + 0x50, (short)-1);
        fn_114_188B8((char*)self + 0x10, (short)-1);
        fn_27_C74E8(self, (short)-1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
