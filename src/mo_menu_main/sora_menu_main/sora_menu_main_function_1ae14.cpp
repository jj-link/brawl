#pragma force_active on
extern "C" {
void fn_11_4D8(void* p);

void fn_2_1AE14(char* self) {
    fn_11_4D8(*(void**)(self + 0x694));
    *(void**)(self + 0x694) = 0;
}
}
