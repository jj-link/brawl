#pragma force_active on
extern "C" {
void fn_800FBF90(void* p);

void fn_800DCA94(char* self) {
    fn_800FBF90(*(void**)(self + 0x8C));
    *(void**)(self + 0xAC) = 0;
}
}
