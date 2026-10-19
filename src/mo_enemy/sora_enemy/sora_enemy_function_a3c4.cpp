#pragma force_active on
extern "C" {
void reset__18gfGameFrameCounterFv(void*);
void start__18gfGameFrameCounterFv(void*);

void fn_41_A3C4(void* self, int index) {
    if (index <= -1 || index >= 4)
        return;

    self = (char*)self + index * 12;
    void* counter = (char*)self + 0x52E0;
    reset__18gfGameFrameCounterFv(counter);
    start__18gfGameFrameCounterFv(counter);
}
}
