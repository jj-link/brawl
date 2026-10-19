#pragma force_active on
extern "C" void fn_27_1999C4(void* self, int a, int b);
extern "C" void fn_27_19BF3C(void* self, int a, int b);
extern "C" void fn_27_150320(void* self, void* a, short b, void* c, void* d);

extern "C" void* fn_97_8DA0(void* self, void* arg, int arg2) {
    fn_27_1999C4(self, 10, 0);
    fn_27_19BF3C((char*)self + 0x584, 2, 0);
    fn_27_150320((char*)self + 0x5b8, arg, (short)arg2, self, (char*)((int)self + 0x584));
    return self;
}
