#pragma force_active on
extern "C" {
void* fn_93_CD48(void*, int);
void* fn_93_CD00(void*, int);
void* fn_93_CCE8(void*, int);
void* fn_93_CCD0(void*, int);
void* fn_93_CCB8(void*, int);
void* fn_93_CCA0(void*, int);
int fn_27_8D3E4(void*);
}

extern "C" void fn_93_CA58(char* self) {
    for (int i = 0; i < 1; ++i) {
        void* article = fn_93_CD48(self + 0x106fc, i);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int i = 0; i < 4; ++i) {
        void* article = fn_93_CD00(self + 0x8778, i);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int i = 0; i < 1; ++i) {
        void* article = fn_93_CCE8(self + 0x6608, i);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int i = 0; i < 1; ++i) {
        void* article = fn_93_CCD0(self + 0x2db4, i);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int i = 0; i < 1; ++i) {
        void* article = fn_93_CCB8(self + 0x16e0, i);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int i = 0; i < 1; ++i) {
        void* article = fn_93_CCA0(self + 0xc, i);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
}