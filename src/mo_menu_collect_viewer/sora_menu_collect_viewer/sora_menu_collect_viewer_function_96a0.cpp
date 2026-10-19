#pragma force_active on
extern "C" {
void fn_8014D108(void* obj, int value);

void fn_6_96A0(char* self) {
    fn_8014D108(*(void**)(self + 0x730), 1);
    *(int*)(self + 0x788) = 2;
}
}
