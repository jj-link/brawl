#pragma force_active on
extern "C" {
void fn_800F01C0(void* a);
void fn_801B354C(void* a, int b);
}

extern "C" void fn_800DCA0C(unsigned char* self) {
    fn_800F01C0(*(void**)(self + 0x70));
    fn_801B354C(*(void**)(self + 0x18), 0);
    self[0xA9] = 0;
}
