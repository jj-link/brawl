#pragma force_active on
extern "C" {
void fn_27_1999C4(void* a, int b, int c);
void fn_27_19BF3C(void* a, int b, int c);
void fn_27_150320(void* a, void* b, short c, void* d, void* e);
void* fn_94_7960(void* self, void* arg2, short arg3);
}

void* fn_94_7960(void* self, void* arg2, short arg3)
{
    fn_27_1999C4(self, 10, 0);
    fn_27_19BF3C((char*)self + 0x584, 2, 0);
    fn_27_150320((char*)self + 0x5b8, arg2, arg3, self, (void*)((int)self + 0x584));
    return self;
}
