extern "C" {
void* fn_98_B6A8(void* bank, int index);
void* fn_98_B67C(void* bank, int index);
void* fn_98_B664(void* bank, int index);
void* fn_98_B62C(void* bank, int index);
int fn_27_8D3E4(void* article);
}

// Visit the four article banks in order; a failed article call ends the traversal.
extern "C" void fn_98_B4A8(char* pool) {
    for (int index = 0; index < 3; ++index) {
        void* owner = fn_98_B6A8(pool + 0x1cb54, index);
        if (fn_27_8D3E4(static_cast<char*>(owner) + 0x88) == 0) return;
    }
    for (int index = 0; index < 2; ++index) {
        void* owner = fn_98_B67C(pool + 0x7f48, index);
        if (fn_27_8D3E4(static_cast<char*>(owner) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        void* owner = fn_98_B664(pool + 0x5f74, index);
        if (fn_27_8D3E4(static_cast<char*>(owner) + 0x88) == 0) return;
    }
    for (int index = 0; index < 3; ++index) {
        void* owner = fn_98_B62C(pool + 0xc, index);
        if (fn_27_8D3E4(static_cast<char*>(owner) + 0x88) == 0) return;
    }
}
