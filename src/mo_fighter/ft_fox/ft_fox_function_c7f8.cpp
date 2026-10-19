#pragma force_active on
extern "C" {
void* fn_97_CA1C(void* object, int index);
void* fn_97_C9C0(void* object, int index);
void* fn_97_C998(void* object, int index);
void* fn_97_C980(void* object, int index);
int fn_27_8D3E4(void*);
}

extern "C" void fn_97_C7F8(char* pool) {
    for (int index = 0; index < 1; ++index) {
        char* article = static_cast<char*>(fn_97_CA1C(pool + 0x12E8C, index));
        if (fn_27_8D3E4(article + 0x88) == 0) return;
    }
    for (int index = 0; index < 5; ++index) {
        char* article = static_cast<char*>(fn_97_C9C0(pool + 0x8708, index));
        if (fn_27_8D3E4(article + 0x88) == 0) return;
    }
    for (int index = 0; index < 2; ++index) {
        char* article = static_cast<char*>(fn_97_C998(pool + 0x4B2C, index));
        if (fn_27_8D3E4(article + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        char* article = static_cast<char*>(fn_97_C980(pool + 0x0C, index));
        if (fn_27_8D3E4(article + 0x88) == 0) return;
    }
}
