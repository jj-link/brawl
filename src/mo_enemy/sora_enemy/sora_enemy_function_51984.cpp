#pragma force_active on
extern "C" void fn_41_51B5C(void*, short);
extern "C" void* fn_41_51924(void* ptr, short flag);

extern "C" void* fn_41_51984(void* self, short flag) {
    if (self) {
        fn_41_51B5C(static_cast<char*>(self) + 0x38, -1);
        fn_41_51924(static_cast<char*>(self) + 4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
