#pragma force_active on
extern "C" void* fn_41_41550(char*, int);
extern "C" void* fn_41_414E8(char*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_4144C(void* p) {
    int i = 0;
    while (i < 2) {
        if (fn_27_8D3E4(
                static_cast<char*>(fn_41_41550(static_cast<char*>(p) + 0x130, i)) +
                0x94) == 0) {
            return;
        }
        ++i;
    }

    i = 0;
    while (i < 6) {
        if (fn_27_8D3E4(fn_41_414E8(static_cast<char*>(p) + 0xC, i)) == 0) {
            return;
        }
        ++i;
    }
}
