#pragma force_active on
extern "C" void fn_800FD96C(int a, int b);

extern "C" void fn_800FCC90(void* self, unsigned int idx) {
    fn_800FD96C(*(int*)(static_cast<char*>(self) + idx * 4 + 0x1c), 0);
}
