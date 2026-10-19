#pragma force_active on
extern "C" {
void fn_27_1999C4(void*, int, int);
void fn_27_19BF3C(void*, int, int);
void fn_27_150320(void*, void*, short, void*, void*);
}

extern "C" int fn_119_65E8(int self, int a1, short a2) {
    fn_27_1999C4((void*)self, 0xa, 0);
    fn_27_19BF3C((void*)(self + 0x584), 2, 0);
    fn_27_150320((void*)(self + 0x5b8), (void*)a1, a2, (void*)self, (void*)(self + 0x584));
    return self;
}
