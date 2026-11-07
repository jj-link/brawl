#pragma force_active on
extern "C" {
void* fn_105_F58C(void* ptr, int index);
void* fn_105_F530(void* object, int index);
void* fn_105_F518(void* object, int index);
void* fn_105_F500(void* object, int index);
void* fn_105_F4E8(void* object, int index);
int fn_27_8D3E4(void*);
}

extern "C" void fn_105_F334(char* self) {
    for (int index = 0; index < 3; ++index) {
        void* article = fn_105_F58C(self + 0x11C10, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 5; ++index) {
        void* article = fn_105_F530(self + 0x68D4, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        void* article = fn_105_F518(self + 0x414C, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        void* article = fn_105_F500(self + 0x2034, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        void* article = fn_105_F4E8(self + 0xC, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
}
