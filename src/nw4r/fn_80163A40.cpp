#pragma force_active on
extern char lbl_80465258[];

extern "C" void fn_80163E50(void*);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_80163A40(void* self, int deleteFlag) {
    if (self != 0) {
        *(void**)((char*)self + 0x1C) = lbl_80465258;
        fn_80163E50(self);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
