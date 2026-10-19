#pragma force_active on
extern "C" {
void fn_27_3774AC(void*);
void fn_27_13604C(void*, void*, unsigned int, void*);

void fn_116_1FDE0(char* self, void* a, unsigned int mode, void* c) {
    if (mode == 1) {
        fn_27_3774AC(self + 0x11130);
    }
    fn_27_13604C(self, a, mode, c);
}
}
