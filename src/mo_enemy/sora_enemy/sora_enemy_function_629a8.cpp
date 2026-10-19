#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_6293C(void*, short);
void operator delete(void* p);

extern "C" void* fn_41_629A8(char* self, short shouldDelete) {
    if (self != 0) {
        fn_41_62CC4(self + 0x278, -1);
        fn_41_6293C(self + 4, -1);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
