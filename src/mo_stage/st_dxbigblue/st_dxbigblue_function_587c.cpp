#pragma force_active on
extern "C" {
void fn_81_4F40(void* self, int arg);
void __dl__FPv(void* p);
void* fn_81_587C(void* self, int flag);
}

extern "C" void* fn_81_587C(void* self, int flag) {
    if (self) {
        if (self) {
            fn_81_4F40(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
