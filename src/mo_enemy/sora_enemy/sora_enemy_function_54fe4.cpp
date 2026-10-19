#pragma force_active on
extern "C" void* fn_41_55050(char* p, int flag);
extern "C" int fn_27_8D3E4(void* p);

extern "C" void fn_41_54FE4(char* self) {
    int i = 0;
    while (i < 1) {
        if (fn_27_8D3E4(fn_41_55050(self + 0xc, i)) == 0) {
            break;
        }
        i++;
    }
}
