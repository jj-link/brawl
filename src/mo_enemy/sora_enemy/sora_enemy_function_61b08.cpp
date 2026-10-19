#pragma force_active on
extern "C" void* fn_41_61B74(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_61B08(char* obj) {
    int i = 0;
    while (i < 7) {
        if (fn_27_8D3E4(fn_41_61B74(obj + 0xc, i)) == 0) {
            break;
        }
        i++;
    }
}
