#pragma force_active on
extern "C" void* fn_41_6B12C(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_6B0C0(void* self) {
    for (int i = 0; i < 20; i++) {
        void* p = fn_41_6B12C(static_cast<char*>(self) + 0xc, i);
        if (fn_27_8D3E4(p) == 0) {
            break;
        }
    }
}
