#pragma force_active on
extern "C" void* fn_41_5C0FC(char* p, int n);
extern "C" int fn_27_8D3E4(void* p);

extern "C" {
void fn_41_5C090(char* self) {
    for (int i = 0; i < 5; i++) {
        if (fn_27_8D3E4(fn_41_5C0FC(self + 0xc, i)) == 0) {
            break;
        }
    }
}
}
