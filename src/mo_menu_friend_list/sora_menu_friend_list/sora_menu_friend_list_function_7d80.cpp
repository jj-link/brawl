#pragma force_active on
extern "C" {
void fn_14_39BC(void* self, int mode);
int fn_800B5854(void* p, int a, int b, int c, int d);
void fn_14_3D88(void* self, int v);
void fn_16_5A8(void* self, const char* name, int a, int c);
void fn_14_1C80(void* self, int v);
void fn_14_3C50(void* self);
void printIndex__5MuMsgFUlUlPv(void* msg, unsigned long a, unsigned long b, void* c);
}

extern "C" void fn_14_7D80(void* self) {
    char* s = (char*)self;
    fn_14_39BC(self, 1);
    fn_800B5854(*(void**)(s + 0xb0), 1, 1, 1, 0);
    fn_14_3D88(self, 0);
    fn_16_5A8(s + 0x2570, 0, 0, 5);
    fn_14_1C80(self, 0);
    fn_14_3C50(self);
    printIndex__5MuMsgFUlUlPv(*(void**)(s + 0x24cc), 0x17, 0x14, 0);
}
