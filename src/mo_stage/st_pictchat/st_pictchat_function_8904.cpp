#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void __dla__FPv(void*);
void fn_73_2CC8(void*, int);
extern char lbl_73_data_3A68[];
}

extern "C" void* fn_73_8904(void* self, int flag) {
    if (self) {
        if (self) {
            void* a = *(void**)((char*)self + 0x284);
            *(void**)((char*)self + 0x3C) = lbl_73_data_3A68;
            if (a) __dl__FPv(a);
            *(void**)((char*)self + 0x284) = 0;
            void* b = *(void**)((char*)self + 0x174);
            if (b) __dla__FPv(b);
            *(void**)((char*)self + 0x174) = 0;
            fn_73_2CC8(self, 0);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
