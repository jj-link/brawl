#pragma force_active on
struct Stage {
    char padding[0x320];
    int state;
};

extern "C" void fn_66_55BC(Stage* self, const int* event) {
    int id = *event;

    if (id == 0x33) {
        self->state = 0;
        return;
    }

    if (id <= 0x26 || id >= 0x29)
        return;

    if (id == 0x27)
        self->state = 1;
}
