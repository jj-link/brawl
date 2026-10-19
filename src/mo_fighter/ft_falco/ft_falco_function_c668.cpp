#pragma force_active on
extern "C" {
void* fn_108_C88C(void*, int);
void* fn_108_C830(void*, int);
void* fn_108_C808(void*, int);
void* fn_108_C7F0(void*, int);
int fn_27_8D3E4(void*);
}

extern "C" void fn_108_C668(char* self) {
    for (int index = 0; index < 1; ++index) {
        void* article = fn_108_C88C(self + 0x131f0, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 5; ++index) {
        void* article = fn_108_C830(self + 0x8a80, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 2; ++index) {
        void* article = fn_108_C808(self + 0x4b2c, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        void* article = fn_108_C7F0(self + 0xc, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
}
