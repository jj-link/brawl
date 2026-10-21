#pragma force_active on
extern "C" {
void* fn_110_AA60(void*, int);
void* fn_110_AA48(void*, int);
int fn_27_8D3E4(void*);

void fn_110_A92C(void* object) {
    for (int i = 0; i < 1; ++i) {
        void* member = fn_110_AA60(static_cast<char*>(object) + 0x20b8, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) return;
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_110_AA48(static_cast<char*>(object) + 0x0c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) break;
    }
}
}
