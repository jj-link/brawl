#include <types.h>
#pragma force_active on

#pragma fp_contract off

struct Point {
    f32 x, y;
};

struct State {
    char padding00[0x5c];
    f32 x, y;
    char padding64[0x10];
    f32 tx, ty;
    char padding7c[4];
    f32 vx, vy, ax, ay;
    char padding90[0x10];
    f32 scale;
};

struct Data {
    char padding00[0x90];
    unsigned int flags;
    void* table;
    signed char rate;
    char padding99[0x77];
    signed char id;
};

struct Object {
    char padding00[0x70];
    Data* data;
    State* state;
};

struct Entry {
    char padding00[4];
    unsigned short frames;
    char padding06[2];
    f32 left, right, bottom, top;
};

extern "C" {
extern const f32 lbl_27_rodata_3000[];
State* fn_27_1F1F58(signed char*);
f32 fn_27_21F1BC(signed char*);
f32 fn_27_21F244(signed char*);
unsigned short fn_27_21F7E4(void*, int, int);
Entry* fn_27_21FD30(void*, int);
int fn_27_21FD04(unsigned short);
void fn_27_21F4AC(void*, int);
}

extern "C" void fn_27_212C54(Object* self, int kind) {
    f32 pool;
    f64 conversionBias;
    pool = 0.0f;
    pool = -1.0f;
    pool = 1.0f;
    pool = 0.5f;
    pool = 1.17549435e-38f;
    pool = 0.0001f;
    pool = 0.2f;
    pool = 0.4f;
    pool = 0.01f;
    conversionBias = 4503601774854144.0;
    pool = 0.7f;
    pool = 0.8f;
    pool = 0.9f;
    pool = 40.0f;
    pool = 20.0f;
    pool = -40.0f;
    pool = -20.0f;
    pool = 0.75f;
    pool = 8.0f;
    pool = 5.0f;
    pool = 30.0f;
    pool = 10.0f;
    pool = 1.2f;
    pool = 0.6f;
    pool = 70.0f;
    pool = 80.0f;
    pool = 90.0f;
    pool = 0.02f;
    pool = 50.0f;
    pool = 150.0f;
    pool = 0.005f;
    pool = 0.1f;
    pool = 0.006f;
    pool = 100.0f;
    pool = 120.0f;
    pool = 15.0f;
    pool = 24.0f;
    pool = -0.1f;
    pool = -24.0f;
    pool = 60.0f;
    pool = 110.0f;
    pool = 0.3f;
    pool = 0.05f;
    pool = 0.15f;
    conversionBias = 4503599627370496.0;
    pool = 0.98f;
    pool = 0.85f;
    pool = -0.9f;
    pool = -0.95f;
    pool = 4.0f;
    pool = 0.0625f;
    pool = -0.5f;
    pool = -0.8f;
    pool = -0.2f;
    pool = 0.008333334f;
    pool = 0.008f;
    pool = -0.4f;
    pool = -0.3f;
    pool = -0.7f;
    pool = 1.8f;
    pool = 1.4f;
    pool = 1.035f;
    pool = 89128.96f;
    pool = -0.6f;
    pool = -10.0f;
    pool = -12.0f;
    pool = -30.0f;
    pool = 2.0f;

    Data* data = self->data;
    void* table = data->table;

    if (table) {
        switch (kind) {
        case 0x6026:
            return;
        case 0x6021:
        case 0x6022:
        case 0x6023:
        case 0x6024:
        case 0x6025:
        case 0x6027:
        case 0x6028:
        case 0x6029: {
            f32 frames;
            int i;
            int kindIndex;
            int index = 0;
            State* target = fn_27_1F1F58(&data->id);
            f32 marginX = 2.0f + fn_27_21F1BC(&self->data->id);
            f32 marginY = 2.0f + 0.5f * fn_27_21F244(&self->data->id);

            kindIndex = kind - 0x6016;
            for (;;) {
                unsigned short action =
                    fn_27_21F7E4(&self->data->flags, kindIndex, index);
                Entry* entry = 0;

                if (!action)
                    return;

                switch (kind) {
                case 0x6021:
                    if (action == 0x6041) action = 0;
                    break;
                case 0x6022:
                    if (action == 0x6042) action = 0;
                    break;
                case 0x6023:
                    if (action == 0x6043) action = 0;
                    break;
                case 0x6024:
                    if (action == 0x6044) action = 0;
                    break;
                case 0x6025:
                    if (action == 0x6045) action = 0;
                    break;
                }

                switch (action) {
                case 0x6041:
                    entry = fn_27_21FD30(table, 0x62);
                    break;
                case 0x6042:
                    entry = fn_27_21FD30(table, 0x63);
                    break;
                case 0x6043:
                    entry = fn_27_21FD30(table, 0x64);
                    break;
                case 0x6044:
                    entry = fn_27_21FD30(table, 0x65);
                    break;
                case 0x6045:
                    entry = fn_27_21FD30(table, 0x66);
                    break;
                }

                if (entry) {
                    Point low, high, pos, tpos;
                    f32 dx, dy, targetDx, targetDy;
                    frames =
                        (f32)entry->frames *
                        (0.01f * (f32)self->data->rate);

                    dx = self->state->vx * frames;
                    dy = self->state->vy * frames;
                    targetDx = target->vx * frames;
                    targetDy = target->vy * frames;
                    f32 x, y, targetX, targetY;
                    y = self->state->y;
                    x = self->state->x;
                    targetY = target->ty;
                    targetX = target->tx;
                    pos.x = x + dx;
                    pos.y = y + dy;
                    tpos.x = targetX + targetDx;
                    tpos.y = targetY + targetDy;

                    for (i = 1; i < (int)frames; ++i) {
                        pos.x += self->state->ax * (f32)i;
                        pos.y += self->state->ay * (f32)i;
                        tpos.x += target->ax * (f32)i;
                        tpos.y += target->ay * (f32)i;
                    }

                    low.x = pos.x + entry->left * self->state->scale;
                    high.x = pos.x + entry->right * self->state->scale;
                    low.y = pos.y + entry->bottom;
                    high.y = pos.y + entry->top;

                    if (low.x > high.x) {
                        f32 tmp = low.x;
                        low.x = high.x;
                        high.x = tmp;
                    }
                    if (low.y > high.y) {
                        f32 tmp = low.y;
                        low.y = high.y;
                        high.y = tmp;
                    }

                    low.x -= marginX;
                    high.x += marginX;
                    low.y -= marginY;
                    high.x += marginY;

                    if (tpos.x < low.x || tpos.x > high.x ||
                        tpos.y < low.y || tpos.y > high.y) {
                        fn_27_21F4AC(
                            &self->data->flags,
                            fn_27_21FD04(action)
                        );
                    }
                }
                ++index;
            }
        }
        }
    }
}
