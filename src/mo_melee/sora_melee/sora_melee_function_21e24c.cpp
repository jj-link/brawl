#include <ai/ai_mgr.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct Environment {
    float f00, f04, f08, f0C;
    char pad10[8];
    float f18, f1C, f20, f24, f28;
};

struct FighterState {
    char pad00[0x50];
    unsigned int flags;
    char pad54[8];
    Vec3f position;
    float f68, f6C;
    char pad70[0x10];
    float f80, f84;
    char pad88[0x18];
    float fA0;
    char padA4[4];
    short sA8;
    char padAA[2];
    int action;
    char padB0[0xC];
    Environment* environment;
    char padC0[0xFA];
    unsigned char status;
};

struct Parameters {
    char pad00[0x14];
    float f14, f18;
    char pad1C[4];
    float f20, f24;
};

extern "C" {
extern const float lbl_27_rodata_3290[];
FighterState* fn_27_1F1F58(s8*);
int fn_27_20B568(FighterState*);
int fn_27_20B5AC(FighterState*, s8*);
int fn_27_20B6AC(FighterState*, unsigned int, int);
float fn_27_20B758(FighterState*, s8*, float);
float fn_27_20B898(FighterState*, s8*, float);
float fn_27_20BCBC(FighterState*, Vec3f*, float);
int fn_27_1EFE3C(aiMgr*, Environment*, Environment*, int, float, float, float);
int fn_27_1F2E60(aiMgr*, int);
int fn_27_21E24C(Parameters*, unsigned int, s8*, s8*);
}

extern "C" int fn_27_21E24C(
    Parameters* p, unsigned int kind, s8* selfId, s8* targetId) {
    const float* c = lbl_27_rodata_3290;
    FighterState* self = fn_27_1F1F58(selfId);
    int result = 0;
    FighterState* target = fn_27_1F1F58(targetId);
    Vec3f position = target->position;
    float x = fn_27_20B758(self, targetId, c[1]);
    float y = fn_27_20B898(self, targetId, c[1]);

    switch (kind) {
    case 0:
        result = 1;
        break;

    case 1:
        if (fn_27_20B568(target) == 0 && target->status != 8) {
            Environment* e = self->environment;
            if (!(target->position.m_x > c[9] + e->f18) ||
                !(target->position.m_x < e->f20 - c[9]) ||
                !(target->position.m_y < e->f28 - c[9]))
                result = 1;
        }
        break;

    case 2: {
        float dy = position.m_y - self->position.m_y;
        if (dy > c[7]) {
            if (dy > c[2] && dy < c[17])
                result = 1;
            else if (dy > c[18] && (target->flags & 1) && target->status == 5)
                result = 1;
            else if (target->environment != self->environment) {
                if (!(target->flags & 1))
                    result = 1;
                else if (*(int*)((char*)g_aiMgr + 0x370) == 5 &&
                         position.m_y > c[10])
                    result = 1;
            }
        }
        break;
    }

    case 3:
        if (!(self->flags & 1) &&
            target->environment != self->environment &&
            position.m_y - self->position.m_y < c[19] &&
            fn_27_20B568(target) != 0 &&
            (*(int*)((char*)g_aiMgr + 0x370) != 5 ||
             !(self->position.m_y > c[10]))) {
            if (position.m_y - self->position.m_y < c[20])
                result = 1;
            else if (!(target->flags & 1)) {
                float height = p->f20 * (c[16] + c[21] * self->f6C);
                float width = p->f24 * (c[16] + c[21] * self->f68);
                if (fn_27_1EFE3C(
                        g_aiMgr, self->environment, target->environment, -1,
                        self->position.m_x, width, height))
                    result = 1;
            }
        }
        break;

    case 4:
        if (x >= p->f14)
            result = 1;
        break;

    case 5:
        if (x < p->f14 && x >= p->f18)
            result = 1;
        break;

    case 6:
        if (x < p->f18 && x >= c[1])
            result = 1;
        break;

    case 19: {
        float range = p->f18;
        if (x < c[0] * range && x >= c[1])
            result = 1;
        break;
    }

    case 20: {
        float range = p->f18;
        if (nw4r::ut::Abs(x) < c[0] * range)
            result = 1;
        break;
    }

    case 7:
        if (x < c[1])
            result = 1;
        break;

    case 8:
        if (y >= p->f14)
            result = 1;
        break;

    case 23: {
        float range = p->f18;
        if (y < c[0] * range)
            result = 1;
        break;
    }

    case 9:
        if (self->environment == target->environment)
            result = 1;
        break;

    case 10:
        if (target->status == 4 || target->status == 6)
            result = 1;
        break;

    case 26:
        if (target->status == 5)
            result = 1;
        break;

    case 27:
        if (target->status == 14)
            result = 1;
        break;

    case 11:
        if (self->sA8 > 0 && self->status != 14)
            result = 1;
        break;

    case 12:
        if (self->action == 0 &&
            fn_27_20B6AC(self, 1, -1) == 0 &&
            fn_27_20B568(self) == 0 &&
            self->status != 14)
            result = 1;
        break;

    case 13:
        if (self->flags & 4)
            result = 1;
        break;

    case 14:
        switch (self->action) {
        case 29:
        case 30:
        case 31:
            if (fn_27_20B6AC(self, 1, -1))
                result = 1;
            break;
        }
        break;

    case 15:
        if (fn_27_20B6AC(self, 1, 27) == 0)
            result = 1;
        break;

    case 16:
        switch (self->action) {
        case 22:
            if (fn_27_20B6AC(self, 1, -1) == 0)
                result = 1;
            break;
        case 23:
            if (fn_27_20B6AC(self, 1, -1) == 0)
                result = 1;
            break;
        case 29:
            if (fn_27_20B6AC(self, 2, -1) == 0)
                result = 1;
            break;
        }
        break;

    case 17:
        if ((self->flags & 1) && self->f84 < c[1])
            result = 1;
        break;

    case 18:
        if (self->flags & 1)
            result = 1;
        break;

    case 21:
        if (fn_27_20B5AC(self, selfId) == 0) {
            float value = fn_27_20BCBC(self, &self->position, self->fA0);
            if (value > c[22] && value < c[23]) {
                Environment* e = self->environment;
                if (self->position.m_y > e->f0C - c[9] &&
                    ((self->position.m_x < e->f00 && self->f80 > c[24]) ||
                     (self->position.m_x > e->f08 && self->f80 < c[0])))
                    result = 1;
            }
        }
        break;

    case 22:
        if (fn_27_20B6AC(self, 1, 12))
            result = 1;
        break;

    case 24:
        if (fn_27_21E24C(p, 18, selfId, targetId) == 0 &&
            fn_27_21E24C(p, 1, selfId, targetId) == 0 &&
            fn_27_21E24C(p, 4, selfId, targetId) == 0 &&
            fn_27_21E24C(p, 2, selfId, targetId) != 0 &&
            fn_27_21E24C(p, 9, selfId, targetId) != 0)
            result = 1;
        break;

    case 25:
        if (fn_27_20B6AC(self, 8, 46))
            result = 1;
        break;

    case 28:
        if (fn_27_1F2E60(g_aiMgr, *selfId))
            result = 1;
        break;

    case 29:
        if (fn_27_20B6AC(self, 4, 27) == 0)
            result = 1;
        break;
    }

    return result;
}
