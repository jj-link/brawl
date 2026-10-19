#pragma force_active on
extern "C" {
int fn_14_3424(int a, int b);
int fn_800B5854(void* p, int a, int b, int c, int d);
void fn_14_2D04(void* self);
void fn_14_38A0(void* self, int v);
}

extern "C" void fn_14_7C4C(void* self) {
    fn_14_3424((int)self, 7);
    fn_800B5854(*(void**)((char*)self + 0xb0), 3, 1, 1, 0);
    fn_14_2D04(self);
    if (*(int*)((char*)self + 0x24c0) >= 0x40) {
        fn_14_38A0(self, 0);
    }
}
