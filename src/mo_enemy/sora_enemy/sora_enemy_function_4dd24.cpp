#pragma force_active on
extern "C" void* fn_41_4DD90(char* p, int n);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_4DD24(char* self) {
    for (int i = 0; i < 5; i++) {
        if (fn_27_8D3E4(fn_41_4DD90(self + 0xc, i)) == 0) {
            break;
        }
    }
}
