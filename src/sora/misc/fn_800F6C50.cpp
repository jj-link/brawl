#pragma force_active on
extern "C" {
void fn_800F57F0(void* self, int a, int b, int c, int d, int e);
void fn_800F6DF4(void* self, int a, int b, int c, int d);
}

extern "C" void fn_800F6C50(void* self) {
    fn_800F57F0(self, -1, -1, 0, 0, 0);
    fn_800F6DF4(self, 0, -1, *(int*)((char*)self + 0x42c), 0);
}
