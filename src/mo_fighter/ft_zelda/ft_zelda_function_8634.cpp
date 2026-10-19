#pragma force_active on
extern "C" {
void fn_27_1999C4(char* self, int a, int b);
void fn_27_19BF3C(char* ptr, int a, int b);
void fn_27_150320(char* ptr, char* a, short b, char* c, char* d);
}

extern "C" char* fn_104_8634(char* self, char* arg, short arg2) {
    fn_27_1999C4(self, 10, 0);
    fn_27_19BF3C(self + 0x584, 2, 0);
    fn_27_150320(self + 0x5b8, arg, arg2, self, self + 0x584);
    return self;
}
