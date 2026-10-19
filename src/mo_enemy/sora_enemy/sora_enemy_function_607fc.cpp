#pragma force_active on
extern "C" void fn_41_60968(void* self, short destroy);
extern "C" void fn_41_60790(void* self, short destroy);
void operator delete(void* p);

extern "C" void* fn_41_607FC(void* self, short flag) {
    if (self) {
        fn_41_60968((char*)self + 0xC8, -1);
        fn_41_60790((char*)self + 4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
