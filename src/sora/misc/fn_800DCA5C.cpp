#pragma force_active on
extern "C" {
void fn_800FBDF4(void* p);

void fn_800DCA5C(char* self) {
    fn_800FBDF4(*(void**)(self + 0x8C));
    *(int*)(self + 0xAC) = 1;
}
}
