#pragma force_active on
struct AiInput;
extern "C" void fn_27_1F3844(AiInput*, int);
struct Manager { unsigned char pad[0x4C]; AiInput* items[7]; };
extern "C" void fn_27_1F1AD4(Manager* self, int index, int mode) {
    if ((unsigned int)self + 0x4C == 0) return;
    if (index < 0) return;
    if (index >= 7) return;
    AiInput* item = self->items[index];
    if (item == 0) return;
    if (*(unsigned char*)((char*)self + 0xA0) != 1 &&
        *(signed char*)((char*)self + 0x92 + index) >= 0) return;
    fn_27_1F3844(item, mode);
}