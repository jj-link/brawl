#pragma force_active on
typedef unsigned int u32;
typedef struct State { int init; u32 index; int pad; u32 count; int pad2; int value; } State;
extern State lbl_80537300;
extern int lbl_805A1170;
extern int fn_8039A260(void);
extern int fn_8039A274(void);
extern void *fn_80397748(void *, unsigned char, unsigned long);
extern int fn_803A03F8(State *, void *);
extern int fn_8039B244(void *, int, int);
int fn_803A02A4(char *out, u32 count, u32 *written, u32 *remaining)
{
    State *state = &lbl_80537300;
    u32 i;
    int *buffer;
    int result;
    if (fn_8039A260() == 0 && fn_8039A274() == 0)
        return -9;
    *written = 0;
    *remaining = 0;
    buffer = (int *)(lbl_805A1170 + 0x1a00);
    if (out == 0 && count != 0)
        return -5;
    if (state->init == 0) {
        fn_80397748(buffer, 0, 0x1000);
        result = fn_803A03F8(state, buffer);
        if (result != 0)
            return result;
        state->init = 1;
    }
    if (state->count == 0)
        return 0;
    i = 0;
    while (i < state->count) {
        if (i >= count)
            break;
        result = fn_8039B244(out, state->value, buffer[state->index++]);
        if (result != 0)
            return result;
        out += 0x100;
        i++;
        ++*written;
    }
    state->count -= *written;
    *remaining = state->count;
    return 0;
}