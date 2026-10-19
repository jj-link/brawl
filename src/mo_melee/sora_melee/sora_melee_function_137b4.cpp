#pragma force_active on
extern "C" void fn_27_1F980();

extern "C" void* fn_27_137B4(void* self) {
    fn_27_1F980();
    *(int*)((char*)self + 0x28) = -1;
    return self;
}
