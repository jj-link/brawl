#pragma force_active on
typedef int s32;

extern s32 fn_803F5EA8(void *stream, long offset, s32 origin);
extern s32 fn_803F5CE0(void *stream);
extern void fn_803F5EAC(void *file);

s32 fn_8037F7D8(s32 *self) {
    s32 state;

    state = *(s32 *)(*self);
    self[1] = -1;
    if (state == 0) {
        goto done;
    }
    if (state == 1) {
        if (self[2] == 0) {
            return 0;
        }
        if (fn_803F5EA8((void *)self[2], 0, 2) != 0) {
            return 0;
        }
        self[3] = fn_803F5CE0((void *)self[2]);
        if (self[3] == -1) {
            return 0;
        }
        fn_803F5EAC((void *)self[2]);
    } else if (state != 2 && state != 3) {
        return 0;
    }
done:
    return 1;
}
