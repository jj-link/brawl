#pragma force_active on
typedef int s32;

extern void fn_80212588(s32 p);

void fn_803CC170(s32 *self) {
    self[9] = 0;
    fn_80212588(self[0]);
    self[0] = -1;
}
