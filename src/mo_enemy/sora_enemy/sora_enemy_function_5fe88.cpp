#pragma force_active on
extern "C" void* fn_41_5FEF4(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_5FE88(void* object) {
    int i = 0;
    while (i < 14) {
        if (fn_27_8D3E4(fn_41_5FEF4(static_cast<char*>(object) + 0xc, i)) == 0) {
            break;
        }
        i++;
    }
}
