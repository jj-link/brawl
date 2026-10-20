#pragma force_active on
struct Title {
    char pad[0x58];
    int count;
    int limit;
    int state;
    int timer;
};

extern "C" void fn_24_1544(Title* self) {
    switch (self->state) {
    case 0:
        break;
    case 1:
        self->state = 2;
        break;
    case 2:
        if (self->count <= self->limit + 1) {
            self->state = 3;
        }
        break;
    case 3:
        break;
    }
    self->timer++;
}
