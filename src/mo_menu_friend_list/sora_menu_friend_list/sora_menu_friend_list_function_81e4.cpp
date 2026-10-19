#pragma force_active on
extern "C" {
int fn_800B5854(void* p, int a, int b, int c, int d);
void fn_14_1C80(void* self, int v);
void fn_14_3C50(void* self);
}

extern "C" void fn_14_81E4(void* self) {
    fn_800B5854(*(void**)((char*)self + 0xb0), 2, 1, 1, 0);
    fn_14_1C80(self, 1);
    fn_14_3C50(self);
}
