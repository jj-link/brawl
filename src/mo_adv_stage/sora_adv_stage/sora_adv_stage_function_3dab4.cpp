#pragma force_active on

extern "C" {
void fn_8007EA78(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_40_data_17A04[];
}

extern "C" void* fn_40_3DAB4(void* self, int flag) {
    if (self) {
        *(void**)((char*)self + 0x3C) = lbl_40_data_17A04;
        void* h = *(void**)((char*)self + 0x48);
        if (h) {
            fn_8007EA78(h, 1);
            *(void**)((char*)self + 0x48) = 0;
        }
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
