#pragma force_active on
extern "C" {
void reset__18gfGameFrameCounterFv(void*);
void start__18gfGameFrameCounterFv(void*);

void fn_41_329FC(void* self, int index) {
    if (index <= -1 || index >= 2) return;
    self = (char*)self + index * 12;
    void* counter = (char*)self + 0x221C;
    reset__18gfGameFrameCounterFv(counter);
    start__18gfGameFrameCounterFv(counter);
}
}
