#pragma force_active on
extern "C" void fn_9_1BE0(char* self, unsigned int a, unsigned int b);
extern "C" void fn_9_1F94(char* self, unsigned int a, unsigned int b);

extern "C" void fn_9_25D4(char* self) {
    fn_9_1BE0(self, *(unsigned int*)(self + 0x17B8), *(unsigned int*)(self + 0x17BC));
    fn_9_1F94(self, *(unsigned int*)(self + 0x17B8), *(unsigned int*)(self + 0x17BC));
}
