#pragma force_active on
extern "C" {
void* fn_115_BB08(void* pool, int index);
void* fn_115_BAE0(void* pool, int index);
void* fn_115_BA24(void* pool, int index);
void* fn_115_BA0C(void* pool, int index);
int fn_27_8D3E4(void*);
}

extern "C" void fn_115_B884(char* pool) {
    for (int index = 0; index < 2; ++index) {
        void* object = fn_115_BB08(pool + 0x1a900, index);
        if (fn_27_8D3E4(reinterpret_cast<char*>(object) + 0x88) == 0)
            return;
    }
    for (int index = 0; index < 2; ++index) {
        void* object = fn_115_BAE0(pool + 0x15d0c, index);
        if (fn_27_8D3E4(reinterpret_cast<char*>(object) + 0x88) == 0)
            return;
    }
    for (int index = 0; index < 10; ++index) {
        void* object = fn_115_BA24(pool + 0x1fb0, index);
        if (fn_27_8D3E4(reinterpret_cast<char*>(object) + 0x88) == 0)
            return;
    }
    for (int index = 0; index < 1; ++index) {
        void* object = fn_115_BA0C(pool + 0xc, index);
        if (fn_27_8D3E4(reinterpret_cast<char*>(object) + 0x88) == 0)
            return;
    }
}
