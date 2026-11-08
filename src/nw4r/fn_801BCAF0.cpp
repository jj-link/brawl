#pragma force_active on
extern float lbl_805A34AC;
struct State {
    char pad[0x44];
    float start, end;
    int duration, elapsed;
    char pad54[0x15];
    unsigned char disabled;
    float value() {
        if (elapsed >= duration) return end;
        return start + ((float)elapsed * (end - start)) / (float)duration;
    }
    void reset(float a, float b, int n) {
        start = a; end = b; duration = n; elapsed = 0;
    }
};
extern "C" void fn_801BCAF0(State* self, int frames) {
    if (!self->disabled) {
        float value = self->value();
        int duration = (int)((float)frames * (lbl_805A34AC - value));
        self->reset(self->value(), lbl_805A34AC, duration);
    }
}