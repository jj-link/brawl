#pragma force_active on
#include <types.h>
#include <ef/ef_screen.h>
#include <ef/ef_screen_handle.h>

struct Handle {
    u8 value;
};

struct Owner {
    char pad[0x1b8];
    u8 flag;
};

struct Data {
    char pad[5];
    u8 flag;
    char pad2[6];
    char key[1];
};

struct Self {
    char pad[12];
    Owner* owner;
    Data* data;
    float timer;
    u8 state;
    u8 index;
    u8 started;
    u8 pending;
    s8 handle;
    GXColor colors[5];
    char padding[3];
    float times[1];
};

extern "C" {
extern const float lbl_40_rodata_120[];
extern float lbl_27_data_547E0;
extern void* g_ftManager;
extern void* g_stTriggerMng;

void fn_8005E344(efScreen*, Handle, GXColor*, float);
void fn_8005E3C8(efScreen*, Handle, float);
void fn_40_533C(void*);
void fn_40_7CF8(void*);
void fn_27_109294(void*, int);
void* fn_27_232338(void*, void*);
void fn_27_2346EC(void*, int);
}

extern "C" void fn_40_ED98(Self* s) {
    const float* c = lbl_40_rodata_120;

    if (s->data->flag) {
        switch (s->state) {
        case 0:
            if (!s->started && !s->owner->flag) {
                u8 index = s->index;
                float time = s->times[index];
                GXColor color = s->colors[index];
                s->handle = (unsigned int)g_efScreen->requestFill(time, 7, 0, &color) >> 24;
                s->started = 1;
            }
            if (s->timer > c[26]) {
                s->index++;
                s->state++;
                s->timer = c[11];
                s->started = 0;
            }
            break;

        case 1:
        case 8:
            if (!s->started && !s->owner->flag) {
                if (((efScreenHandle*)&s->handle)->isValid()) {
                    u8 index = s->index;
                    float time = s->times[index];
                    Handle h = { s->handle };
                    GXColor color = s->colors[index];
                    fn_8005E344(g_efScreen, h, &color, time);
                } else {
                    u8 index = s->index;
                    float time = s->times[index];
                    GXColor color = s->colors[index];
                    s->handle = (unsigned int)g_efScreen->requestFill(time, 7, 0, &color) >> 24;
                }
                s->started = 1;
            }
            if (s->timer > s->times[s->index]) {
                s->index++;
                s->state++;
                s->timer = c[11];
                s->started = 0;
            }
            break;

        case 2:
            if (!s->started && !s->owner->flag) {
                u8 index = s->index;
                float time = s->times[index];
                Handle h = { s->handle };
                GXColor color = s->colors[index];
                fn_8005E344(g_efScreen, h, &color, time);
                s->started = 1;
            }
            break;

        case 4:
        case 6:
            if (!s->started && !s->owner->flag) {
                if (((efScreenHandle*)&s->handle)->isValid()) {
                    Handle h = { s->handle };
                    fn_8005E3C8(g_efScreen, h, c[28]);
                    s->handle = -1;
                }
                s->started = 1;
            }
            if (s->timer > s->times[s->index]) {
                u8 state = s->state + 1;
                s->started = 0;
                s->state = state;
                s->timer = c[11];
            }
            break;

        case 3:
        case 5:
            if (!s->started && !s->owner->flag) {
                if (((efScreenHandle*)&s->handle)->isValid()) {
                    Handle h = { s->handle };
                    GXColor color = s->colors[s->index];
                    fn_8005E344(g_efScreen, h, &color, c[28]);
                } else {
                    GXColor color = s->colors[s->index];
                    s->handle = (unsigned int)g_efScreen->requestFill(c[28], 7, 0, &color) >> 24;
                }
                s->started = 1;
            }
            if (s->timer > s->times[s->index]) {
                u8 state = s->state + 1;
                s->started = 0;
                s->state = state;
                s->timer = c[11];
            }
            break;

        case 7: {
            u8 index = s->index + 1;
            s->state++;
            s->index = index;
            s->timer = c[11];
            s->started = 0;
            break;
        }

        case 9: {
            if (!s->owner->flag) {
                Handle h = { s->handle };
                fn_8005E3C8(g_efScreen, h, c[14]);
                s->handle = -1;
            }
            u8 state = s->state + 1;
            s->started = 0;
            s->state = state;
            s->timer = c[11];
            break;
        }
        }
    }

    if (s->pending) {
        fn_40_533C(s->owner);
        fn_27_109294(g_ftManager, 1);
        void* p = fn_27_232338(g_stTriggerMng, s->data->key);
        if (p) {
            fn_27_2346EC(p, 1);
        }
        fn_40_7CF8(s->owner);
        s->pending = 0;
    }

    float time = s->timer;
    float delta = lbl_27_data_547E0;
    s->timer = time + delta;
}
