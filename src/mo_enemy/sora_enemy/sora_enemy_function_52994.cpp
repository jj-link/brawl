#pragma force_active on
extern "C" void* fn_41_52A00(char* p, int n);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_52994(char* p) {
    for (int i = 0; i < 5; i++) {
        if (fn_27_8D3E4(fn_41_52A00(p + 0xc, i)) == 0) {
            break;
        }
    }
}
