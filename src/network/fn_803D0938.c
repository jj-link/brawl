#include <revolution/GX/GXTev.h>
#pragma force_active on

extern void fn_801F3F5C(int, int, int, int, int);
extern void fn_801F3AFC(int);
extern void fn_801F3D08(int, int, int, int, int, int);
extern void fn_801F3CB0(int, int, int, int, int, int);
extern void fn_801F3E80(int, unsigned int);
extern void fn_801F3ED0(unsigned int, unsigned int);

typedef struct {
    char pad[12];
    unsigned char stages;
    char pad2[3];
    int stage;
    unsigned int value;
    int mode;
} Obj;

void fn_803D0938(Obj *self) {
    fn_801F3F5C(self->stage, 0, 1, 2, 3);
    fn_801F3F5C(self->stage + 1, 0, 3, 2, 1);
    GXSetNumTevStages(self->stages);
    fn_801F3AFC(0);
    fn_801F3D08(0, 0, 0, 0, 1, self->mode);
    fn_801F3CB0(0, 0, 0, 0, 1, self->mode);
    fn_801F3E80(0, self->value + 12);
    fn_801F3ED0(0, 0);
}