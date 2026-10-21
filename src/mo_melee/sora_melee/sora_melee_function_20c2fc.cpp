#pragma force_active on

struct Vec2 {
    float x, y;

    Vec2(float a, float b) : x(a), y(b) {}
};

struct State {
    char pad0[3];
    signed char status;
    char pad4[0x58];
    Vec2 position;
    char pad64[0x58];
    unsigned int id;
    char padC0[8];
    int fieldC8;
};

struct Manager {
    char pad[0x358];
    unsigned short count;
};

extern "C" {
extern Manager* g_aiMgr;
extern const float lbl_27_rodata_2FF4;

float fn_27_21F434(void*, State*);
float fn_27_21F484(void*, State*);
unsigned int fn_27_1EEAA8(
    Manager*, unsigned int, float, float, float, float,
    int, int, Vec2*, int, int);
}

extern "C" int fn_27_20C2FC(State* self, void* parameters) {
    if (self->status < 0) {
        Manager* manager = g_aiMgr;

        if (manager->count <= 1U) {
            self->status = 0;
        } else {
            Vec2 position(self->position.x, self->position.y);
            float a = fn_27_21F434(parameters, self);

            if (self->id == fn_27_1EEAA8(
                    manager, self->id, position.x,
                    fn_27_21F484(parameters, self),
                    a, lbl_27_rodata_2FF4,
                    0, self->fieldC8, &position, 1, 0)) {
                self->status = 0;
            } else {
                self->status = 1;
            }
        }
    }

    return self->status > 0;
}
