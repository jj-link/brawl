#pragma force_active on
extern "C" {
void* fn_112_BE98(void*, int);
void* fn_112_BE50(void*, int);
void* fn_112_BE38(void*, int);
int fn_27_8D3E4(void*);
}

extern "C" void fn_112_BCE0(char* self) {
    for (int index = 0; index < 1; ++index) {
        void* article = fn_112_BE98(self + 0x20040, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 4; ++index) {
        void* article = fn_112_BE50(self + 0x180bc, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        void* article = fn_112_BE38(self + 0xc, index);
        if (fn_27_8D3E4(static_cast<char*>(article) + 0x88) == 0) return;
    }
}
