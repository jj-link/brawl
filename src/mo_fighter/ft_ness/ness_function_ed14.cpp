extern "C" {
void* fn_101_F0B8(void* object, int index);
void* fn_101_F090(void* object, int index);
void* fn_101_F064(void* object, int index);
void* fn_101_EF30(void* object, int index);
void* fn_101_EF18(void* object, int index);
void* fn_101_EF00(void* object, int index);
int fn_27_8D3E4(void* object);
}

// Visit each article bank in order, stopping at the first failed controller call.
extern "C" void fn_101_ED14(void* object) {
    for (int i = 0; i < 1; ++i) {
        void* member = fn_101_F0B8(static_cast<char*>(object) + 0x408F0, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 2; ++i) {
        void* member = fn_101_F090(static_cast<char*>(object) + 0x3C0CC, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 2; ++i) {
        void* member = fn_101_F064(static_cast<char*>(object) + 0x20498, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 16; ++i) {
        void* member = fn_101_EF30(static_cast<char*>(object) + 0x4314, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_101_EF18(static_cast<char*>(object) + 0x21D0, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
    for (int i = 0; i < 1; ++i) {
        void* member = fn_101_EF00(static_cast<char*>(object) + 0xC, i);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            return;
        }
    }
}
