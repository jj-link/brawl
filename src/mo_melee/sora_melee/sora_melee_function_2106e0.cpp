#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

// Matches 99.9%. Remaining diff: 4 lines in the second fn_27_1ED3D8 call block,
// where *outY and pos.y swap between f1 and f2 (register assignment, not fixed).
// Tried and rejected (all higher line counts): swapping the start1/end1 call order (20),
// direct member assignment for end1 (6), end1.setYX(*outY, *outX) (6),
// swapping the start1/end1 declaration order (11).

struct V2 {
    float x, y;
    void set(float a, float b) { x = a; y = b; }
    void setYX(float b, float a) { x = a; y = b; }
};

struct V3 {
    float x, y, z;
};

struct Bounds {
    char pad[0x18];
    V2 a, b;
};

struct State {
    char pad[0x5c];
    V3 pos;
    char pad2[0x54];
    Bounds* bounds;
};

struct Object {
    char pad[0x74];
    State* state;
    char pad2[0x98];
    float value;
};

extern "C" {
extern const float lbl_27_rodata_3000[];
extern void* g_aiMgr;

int fn_27_20B568(State*);
int fn_27_1ED3D8(void*, V2*, V2*, int, int, int);
}

extern "C" void fn_27_2106E0(
    Object* self, float* outX, float* outY, int flag
) {
    const float* R = lbl_27_rodata_3000;
    State* state = self->state;
    Bounds* bounds = state->bounds;
    V3 pos = state->pos;
    V2 a = bounds->a;
    V2 b = bounds->b;

    if (!flag && !fn_27_20B568(state)) {
        float x, y, dir;
        if (pos.x > R[3] * (a.x + b.x)) {
            x = b.x;
            y = b.y;
            dir = R[2];
        } else {
            x = a.x;
            y = a.y;
            dir = R[1];
        }

        if (pos.y < y &&
            dir * (pos.x - (x + R[16] * dir)) < R[0] &&
            (pos.y < y - R[16] || dir * (pos.x - x) < R[0])) {
            float da = nw4r::ut::Abs(pos.x - a.x);
            float db = nw4r::ut::Abs(pos.x - b.x);

            if (da < db) {
                *outX = a.x - R[16];
                *outY = a.y - R[2];
            } else {
                *outX = R[16] + b.x;
                *outY = b.y - R[2];
            }

            if (nw4r::ut::Abs(a.x - b.x) <= R[30]) {
                V2 start, end;
                V2 start1, end1;
                end.set(*outX, pos.y);
                start.set(pos.x, pos.y);

                if (fn_27_1ED3D8(g_aiMgr, &start, &end, 0x1c, 0, 0) ||
                    (end1.set(*outX, *outY),
                     start1.setYX(pos.y, *outX),
                     ((int (*)(void*, V2*, V2*, int, int, int, float))fn_27_1ED3D8)(g_aiMgr, &start1, &end1, 0x1c, 0, 0, pos.y))) {
                    float nx, ny;
                    if (da < db) {
                        nx = R[23] + b.x;
                        ny = b.y - R[2];
                    } else {
                        nx = a.x - R[23];
                        ny = a.y - R[2];
                    }

                    V2 start2, end2;
                    end2.x = nx;
                    end2.y = pos.y;
                    start2.x = pos.x;
                    start2.y = pos.y;

                    if (!fn_27_1ED3D8(
                            g_aiMgr, &start2, &end2, 0x1c, 0, 0)) {
                        V2 start3, end3;
                        end3.x = nx;
                        end3.y = ny;
                        start3.x = nx;
                        start3.y = pos.y;

                        if (!fn_27_1ED3D8(
                                g_aiMgr, &start3, &end3, 0x1c, 0, 0)) {
                            *outX = nx;
                            *outY = ny;
                        }
                    }
                }
            }
            return;
        }

        if ((pos.x < a.x && pos.y < R[37] + a.y) ||
            (pos.x > b.x && pos.y < R[37] + b.y)) {
            if (nw4r::ut::Abs(pos.x - a.x) <
                nw4r::ut::Abs(pos.x - b.x)) {
                *outX = R[2] + a.x;
                *outY = a.y;
            } else {
                *outX = b.x - R[2];
                *outY = b.y;
            }
            return;
        }
    }

    float t = R[43] + R[7] * self->value;
    float u = R[2] - t;
    *outX = a.x * t + b.x * u;
    *outY = a.y * t + b.y * u;
}
