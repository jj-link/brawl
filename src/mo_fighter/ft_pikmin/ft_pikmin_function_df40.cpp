#pragma force_active on
extern "C" {
void* fn_113_E0C0(void*, int);
void* fn_113_E0A8(void*, int);
void* fn_113_E090(void*, int);
int fn_27_8D3E4(void*);

void fn_113_DF40(void* object) {
    for (int i = 0; i < 6; ++i) {
        void* member = fn_113_E0C0(static_cast<char*>(object) + 0x438c, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) return;
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_113_E0A8(static_cast<char*>(object) + 0x1f58, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) return;
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_113_E090(static_cast<char*>(object) + 0xc, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) return;
    }
}
}
