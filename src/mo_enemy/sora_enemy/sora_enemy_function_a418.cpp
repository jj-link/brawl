#pragma force_active on
class gfGameFrameCounter {
public:
    void stop();
    unsigned char data[12];
};

struct Enemy {
    unsigned char padding[0x52E0];
    gfGameFrameCounter counters[4];
};

extern "C" void fn_41_A418(Enemy* self, int index) {
    if (index <= -1 || index >= 4) {
        return;
    }
    self->counters[index].stop();
}
