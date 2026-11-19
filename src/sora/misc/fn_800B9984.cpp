#include <types.h>
#include <gf/gf_application.h>

#pragma force_active on

struct Vec2 {
    float x, y;

    Vec2() {}
    Vec2(const Vec2& other) {
        x = other.x;
        y = other.y;
    }

    Vec2& operator=(const Vec2& other) {
        x = other.x;
        y = other.y;
        return *this;
    }
};

struct PadStatus {
    int w[6];
    Vec2 v[3];
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8;
    int last;
};

extern "C" {
void fn_800B9F90(PadStatus*, void*, int);
s32 fn_800BA178(s32);
extern u32 lbl_80407BF8[4];
extern const u8 lbl_805A2240[8];
}

struct Edge {
    s32 state;
    u8 cnt0, cnt1, pad[2];
};

struct Self {
    u8 pad0[4];
    u8 bits;
    u32 maskA, riseA, heldA;
    u32 maskB, riseB, heldB;
    u32 maskC, riseC, heldC;
    Edge edgesA[4], edgesB[4], edgesC[4];
    s32 prevMode, modeOut, modeHold;
    Edge timer;
    u8 flagArg, initialized, padA2[2];
    u32 lastGfVal;
};

static inline u32 stickMask(u32 mask, const unsigned char* axis) {
    u32 result = mask & ~15;
    if (__abs((s8)axis[0]) > 60) {
        int dir = 1;
        if ((s8)axis[0] > 0)
            dir = 2;
        result |= dir;
    }
    if (__abs((s8)axis[1]) > 60) {
        int dir = 4;
        if ((s8)axis[1] > 0)
            dir = 8;
        result |= dir;
    }
    return result;
}

static inline bool advanceEdge(Edge* e, bool tick) {
    if (tick && ++e->cnt0 >= lbl_805A2240[e->state * 2]) {
        e->cnt0 = 0;
        s32 state = e->state;
        if (state < 3) {
            if (++e->cnt1 >= lbl_805A2240[state * 2 + 1]) {
                e->cnt1 = 0;
                e->state = state + 1;
            }
        }
        return true;
    }
    return false;
}

static inline void updateGroup(Edge* edges, u32 input, bool tick, u32* held) {
    s32 state;
    *held = 0;
    Edge* edge = edges;
    const u32* masks = lbl_80407BF8;
    for (int i = 0; i < 4; i++, ++masks, ++edge) {
        u32 mask = *masks;
        bool repeat;
        u8 cnt;
        if (!(input & mask)) {
            edge->state = 0;
            edge->cnt0 = 0;
            edge->cnt1 = 0;
            repeat = false;
        } else if (tick &&
                   (cnt = edge->cnt0 + 1, edge->cnt0 = cnt,
                    cnt >= lbl_805A2240[edge->state * 2])) {
            edge->cnt0 = 0;
            state = edge->state;
            if (state < 3) {
                if (++edge->cnt1 >= lbl_805A2240[state * 2 + 1]) {
                    edge->cnt1 = 0;
                    edge->state = state + 1;
                }
            }
            repeat = true;
        } else {
            repeat = false;
        }
        if (repeat)
            *held |= mask;
    }
}

extern "C" void fn_800B9984(Self* self) {
    s32 direction, magnitude, sign, value;

    if (self->bits != 0) {
        bool changed = false;
        u32 gfVal = *(u32*)((char*)g_gfApplication + 0x100);
        if (self->initialized == 0) {
            self->initialized = 1;
            changed = true;
        } else if (gfVal != self->lastGfVal) {
            changed = true;
        }
        if (changed)
            self->lastGfVal = gfVal;

        PadStatus status, tmp;
        fn_800B9F90(&tmp, self, self->flagArg);
        status = tmp;

        u32 w1 = status.w[1];
        u32 a, b, c;
        if (w1 & 0xF)
            a = w1;
        else
            a = stickMask(w1, &status.b0);
        b = stickMask(0, &status.b2);
        c = stickMask(w1, &status.b0);

        self->riseA = a & (a ^ self->maskA);
        self->riseB = b & (b ^ self->maskB);
        self->riseC = c & (c ^ self->maskC);
        updateGroup(self->edgesA, a, changed, &self->heldA);
        updateGroup(self->edgesB, b, changed, &self->heldB);
        updateGroup(self->edgesC, c, changed, &self->heldC);
        self->maskA = a;
        self->maskB = b;
        self->maskC = c;

        s32 mode = fn_800BA178(a);
        if (mode != 8 && self->prevMode != mode)
            self->modeOut = mode;
        else
            self->modeOut = 8;
        self->modeHold = 8;
        if (mode != 8) {
            if (advanceEdge(&self->timer, changed))
                self->modeHold = mode;
        } else {
            self->timer.state = 0;
            self->timer.cnt0 = 0;
            self->timer.cnt1 = 0;
        }
        self->prevMode = mode;
    }
}
