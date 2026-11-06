#pragma force_active on
extern "C" {
void* fn_121_CD44(void*, int);
void* fn_121_CCFC(void*, int);
void* fn_121_CCE4(void*, int);
void* fn_121_CCCC(void*, int);
void* fn_121_CCB4(void*, int);
void* fn_121_CC9C(void*, int);
int fn_27_8D3E4(void*);
}

extern "C" void fn_121_CA54(char* self) {
    for (int index = 0; index < 1; ++index) {
        void* article = fn_121_CD44(self + 0x106FC, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 4; ++index) {
        void* article = fn_121_CCFC(self + 0x8778, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        void* article = fn_121_CCE4(self + 0x6608, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        void* article = fn_121_CCCC(self + 0x4F34, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        void* article = fn_121_CCB4(self + 0x16E0, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        void* article = fn_121_CC9C(self + 0xC, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
}
