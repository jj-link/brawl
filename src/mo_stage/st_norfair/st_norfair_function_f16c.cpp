#pragma force_active on

extern "C" {
void __dl__FPv(void*);
void* fn_54_2CB0(void*, int);
char lbl_54_data_39E8[];
}

extern "C" void* fn_54_F16C(void* self, int flag) {
    if (self != 0) {
        void* old = *(void**)((char*)self + 0x1d4);
        *(void**)((char*)self + 0x3c) = &lbl_54_data_39E8;
        if (old != 0) {
            __dl__FPv(old);
        }
        *(void**)((char*)self + 0x1d4) = 0;
        fn_54_2CB0(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
