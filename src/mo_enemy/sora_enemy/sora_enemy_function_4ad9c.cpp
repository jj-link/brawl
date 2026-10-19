#pragma force_active on
extern "C" void* fn_41_4AE08(char*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_4AD9C(void* object) {
    for (int i = 0; i < 3; ++i) {
        if (fn_27_8D3E4(fn_41_4AE08(static_cast<char*>(object) + 0x0C, i)) == 0) {
            break;
        }
    }
}
