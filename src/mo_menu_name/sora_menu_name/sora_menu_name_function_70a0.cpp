#pragma force_active on

struct Self {
    int pad[0x40 / 4];
    int value40;
    int delay;
    int retries;
    int pad2[(0xD0 - 0x4C) / 4];
    int result;
    int status;
};

struct gfPadSystem;

extern "C" {
int fn_16_6E10();
extern gfPadSystem* g_gfPadSystem;
void readGameDataRequest__11gfPadSystemFiiii(gfPadSystem*, int, int, int, int);
}

extern "C" void fn_16_70A0(Self* self) {
    if (self->delay > 0) {
        self->delay -= 1;
        if (self->delay <= 0) {
            readGameDataRequest__11gfPadSystemFiiii(
                g_gfPadSystem, (unsigned char)self->value40,
                (int)((char*)self + 0x50), 0x40, 0);
        }
    } else {
        int result = fn_16_6E10();
        if (result != 1) {
            if (result == 0) {
                self->result = 0;
                self->status = 0;
            } else if (self->retries >= 3) {
                self->result = result;
                self->status = 0;
            } else {
                self->retries += 1;
                self->delay = 5;
            }
        }
    }
}
