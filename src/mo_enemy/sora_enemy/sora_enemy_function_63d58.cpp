#pragma force_active on
extern "C" void* fn_41_63DC4(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_63D58(void* p) {
    int i = 0;
    while (i < 20) {
        void* x = fn_41_63DC4(static_cast<char*>(p) + 12, i);
        if (fn_27_8D3E4(x) == 0) {
            break;
        }
        ++i;
    }
}
