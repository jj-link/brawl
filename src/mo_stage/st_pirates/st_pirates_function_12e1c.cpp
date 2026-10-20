#pragma force_active on
extern "C" {
void fn_52_363C(void* self, int flags);
extern char lbl_52_data_44B8[];
void __dl__FPv(void* p);
}

extern "C" void* fn_52_12E1C(void* self, int flag) {
    if (self != 0) {
        if (self != 0) {
            char* obj = (char*)self;
            void* p = *(void**)(obj + 0x19c);
            *(char**)(obj + 0x3c) = lbl_52_data_44B8;
            if (p != 0) {
                __dl__FPv(p);
            }
            *(void**)(obj + 0x19c) = 0;
            fn_52_363C(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
