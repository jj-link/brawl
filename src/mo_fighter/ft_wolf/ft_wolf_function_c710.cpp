#pragma force_active on
extern "C" {
void* fn_125_C934(void* object, int index);
void* fn_125_C8D8(void* object, int index);
void* fn_125_C8B0(void* object, int index);
void* fn_125_C898(void* object, int index);
int fn_27_8D3E4(void* object);
}

// Walk four article banks in order, stopping at the first failed controller call.
extern "C" void fn_125_C710(char* pool) {
    for (int index = 0; index < 1; ++index) {
        char* article = static_cast<char*>(fn_125_C934(pool + 0x12e8c, index));
        if (fn_27_8D3E4(article + 0x88) == 0) return;
    }
    for (int index = 0; index < 5; ++index) {
        char* article = static_cast<char*>(fn_125_C8D8(pool + 0x8708, index));
        if (fn_27_8D3E4(article + 0x88) == 0) return;
    }
    for (int index = 0; index < 2; ++index) {
        char* article = static_cast<char*>(fn_125_C8B0(pool + 0x4b2c, index));
        if (fn_27_8D3E4(article + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        char* article = static_cast<char*>(fn_125_C898(pool + 0xc, index));
        if (fn_27_8D3E4(article + 0x88) == 0) return;
    }
}
