#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_62570(void*, short);

extern "C" void* fn_41_625DC(void* self, short shouldDelete) {
    if (self != 0) {
        short neg = -1;
        fn_41_62CC4((char*)self + 0xC8, neg);
        fn_41_62570((char*)self + 0x4, neg);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
