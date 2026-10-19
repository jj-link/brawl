#pragma force_active on
extern "C" void fn_41_5D12C(void* ptr, short count);
extern "C" void* fn_41_5CEF4(void* ptr, short shouldDelete);

extern "C" void* fn_41_5CF54(void* self, short shouldDelete) {
    if (self) {
        short neg = -1;
        fn_41_5D12C(static_cast<char*>(self) + 0x38, neg);
        fn_41_5CEF4(static_cast<char*>(self) + 4, neg);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
