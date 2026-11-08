#pragma force_active on
extern "C" {
void* fn_95_D154(void*, int);
void* fn_95_D10C(void*, int);
void* fn_95_D0F4(void*, int);
void* fn_95_D0AC(void*, int);
void* fn_95_D084(void*, int);
int fn_27_8D3E4(void*);
}
extern "C" void fn_95_CEC8(char* pool) {
    for (int i = 0; i < 2; ++i) {
        void* p = fn_95_D154(pool + 0x15dd4, i);
        if (fn_27_8D3E4(static_cast<char*>(p) + 0x88) == 0) return;
    }
    for (int i = 0; i < 4; ++i) {
        void* p = fn_95_D10C(pool + 0xddd0, i);
        if (fn_27_8D3E4(static_cast<char*>(p) + 0x88) == 0) return;
    }
    for (int i = 0; i < 1; ++i) {
        void* p = fn_95_D0F4(pool + 0xbcb4, i);
        if (fn_27_8D3E4(static_cast<char*>(p) + 0x88) == 0) return;
    }
    for (int i = 0; i < 4; ++i) {
        void* p = fn_95_D0AC(pool + 0x3fd0, i);
        if (fn_27_8D3E4(static_cast<char*>(p) + 0x88) == 0) return;
    }
    for (int i = 0; i < 2; ++i) {
        void* p = fn_95_D084(pool + 0xc, i);
        if (fn_27_8D3E4(static_cast<char*>(p) + 0x88) == 0) return;
    }
}