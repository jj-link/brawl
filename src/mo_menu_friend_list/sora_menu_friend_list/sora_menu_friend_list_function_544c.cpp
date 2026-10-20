#pragma force_active on
extern "C" int fn_14_3424(int a, int b);
extern "C" int fn_800B5854(void* p, int a, int b, int c, int d);

extern "C" void fn_14_544C(int self) {
    fn_14_3424(self, *(int*)(self + 0x24c0) <= 3 ? 0xa : 0x10);
    fn_800B5854(*(void**)(self + 0x9c), 1, 1, 1, 0);
    fn_800B5854(*(void**)(self + 0xa0), 1, 0x10, 1, 0);
}
