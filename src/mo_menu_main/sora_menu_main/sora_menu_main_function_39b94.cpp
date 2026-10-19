#pragma force_active on
extern "C" {
void fn_16_5A8(void* self, const char* name, int a, int c);
int fn_800B5854(void* p, int a, int b, int c, int d);
void printIndex__5MuMsgFUlUlPv(void* msg, unsigned long a, unsigned long b, void* c);
}

extern "C" void fn_2_39B94(void* self) {
    fn_16_5A8((char*)self + 0x14c, 0, 0, 5);
    fn_800B5854(*(void**)((char*)self + 0x44), 2, 1, 1, 0);
    printIndex__5MuMsgFUlUlPv(*(void**)((char*)self + 0x74), 5, 0x16, 0);
}
