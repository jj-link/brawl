#pragma force_active on

extern "C" {
int fn_8016FBC8(void*);
void* fn_8016FBF4(void*);
unsigned short fn_801643D0(void);
void fn_80163E50(void*);
}

extern "C" void fn_8005C898(unsigned char* self) {
    if (fn_8016FBC8(self + 0x4C)) {
        void* handle = fn_8016FBF4(self + 0x4C);
        if (fn_801643D0()) {
            fn_80163E50(handle);
        }
    }
}
