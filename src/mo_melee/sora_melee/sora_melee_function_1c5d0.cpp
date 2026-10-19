#pragma force_active on
extern "C" {
void fn_27_13EF4(void* self);
}

extern "C" void* fn_27_1C5D0(char* self) {
    fn_27_13EF4(self);
    void* prev = *(void**)(self + 0x94);
    *(void**)(self + 0x94) = 0;
    return prev;
}
