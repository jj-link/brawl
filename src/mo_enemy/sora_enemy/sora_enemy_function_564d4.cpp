#pragma force_active on
extern "C" void* fn_41_56540(void* obj, int idx);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_564D4(char* obj) {
    for (int i = 0; i < 5; i++) {
        if (fn_27_8D3E4(fn_41_56540(obj + 0xc, i)) == 0) {
            break;
        }
    }
}
