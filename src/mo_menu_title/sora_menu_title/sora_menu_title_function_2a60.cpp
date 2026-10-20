#pragma force_active on
struct TitleState {
    unsigned char padding[0x58];
    int field58;
    int field5C;
    int state;
    int counter;
};

extern "C" void fn_24_2A60(TitleState* self) {
    switch (self->state) {
    case 0:
        break;
    case 1:
        self->state = 2;
        break;
    case 2:
        if (self->field58 <= self->field5C + 1) {
            self->state = 3;
        }
        break;
    case 3:
        break;
    }
    self->counter++;
}
