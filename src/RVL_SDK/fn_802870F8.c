#pragma force_active on
typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct State {
    char pad[0x40];
    Vec4 a;
    Vec4 b;
    char pad60[0x20];
    Vec4 previous;
} State;

extern float lbl_805A3D70;
extern void fn_802879F8(Vec4 *out, State *state, const Vec4 *in);

void fn_802870F8(const Vec4 *input, State *state)
{
    __declspec(align(16)) Vec4 delta;
    __declspec(align(16)) Vec4 result;
    float w = input->w;
    float z = input->z;
    float y = input->y;
    float x = input->x;
    float bz, by, bx, az, ay, ax;

    delta.x = x - state->previous.x;
    delta.y = y - state->previous.y;
    delta.z = z - state->previous.z;
    delta.w = w - state->previous.w;

    state->previous.x = x;
    state->previous.y = y;
    state->previous.z = z;
    state->previous.w = w;

    fn_802879F8(&result, state, &delta);
    result.w = lbl_805A3D70;

    ax = state->a.x;
    ay = state->a.y;
    az = state->a.z;
    bx = state->b.x;
    by = state->b.y;
    bz = state->b.z;

    state->a.x = ax + result.x;
    state->a.y = ay + result.y;
    state->a.z = az + result.z;
    state->b.x = bx + result.x;
    state->b.y = by + result.y;
    state->b.z = bz + result.z;
}
