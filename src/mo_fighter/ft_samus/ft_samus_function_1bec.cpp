#pragma force_active on
typedef short s16;
extern "C" void fn_94_1AD0(void* self, s16 arg);
void operator delete(void* p);

extern "C" void* fn_94_1BEC(void* self, s16 flag) {
    if (self != 0) {
        fn_94_1AD0(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
