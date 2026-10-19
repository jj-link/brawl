#pragma force_active on
struct AdvMenuVisualState {
    char pad[0xB4];
    int first;
    int second;
};

extern "C" int fn_29_2BAC(const AdvMenuVisualState* self) {
    if (self->first >= 2 && self->second >= 2) {
        return 1;
    } else {
        return 0;
    }
}
