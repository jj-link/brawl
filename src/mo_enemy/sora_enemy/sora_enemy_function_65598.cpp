#pragma force_active on
extern "C" void fn_41_65698(void*, short);
extern "C" void fn_41_6552C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_65598(void* self, short shouldDelete) {
    if (self != 0) {
        fn_41_65698(static_cast<char*>(self) + 0x368, -1);
        fn_41_6552C(static_cast<char*>(self) + 4, -1);
        if (shouldDelete > 0)
            __dl__FPv(self);
    }
    return self;
}
