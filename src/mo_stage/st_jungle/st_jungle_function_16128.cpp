#pragma force_active on
extern "C" {
void fn_51_289C(void* self, int flag);
void __dl__FPv(void* p);
extern char lbl_51_data_97C8[];

void* fn_51_16128(void* self, int flag) {
    char* c = (char*)self;
    if (self != 0) {
        if (self != 0) {
            void* p = *(void**)(c + 0x174);
            *(void**)(c + 0x3c) = lbl_51_data_97C8;
            if (p != 0) {
                __dl__FPv(p);
            }
            *(void**)(c + 0x174) = 0;
            fn_51_289C(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
