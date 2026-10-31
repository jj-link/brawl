#pragma force_active on
extern "C" void start__18gfGameFrameCounterFv(void*);

extern "C" void fn_41_A440(char* self, int index)
{
    if (index <= -1 || index >= 4) {
        return;
    } else {
        start__18gfGameFrameCounterFv(self + index * 12 + 0x52E0);
    }
}
