#pragma force_active on
struct Vec { float x, y, z; };
struct Bounds { float left, a, b, right; };
struct Stage {
    char pad0[0x9c];
    Bounds* bounds;
    char padA0[0x1c];
    Vec* output;
    char padC0[0x119];
    unsigned char state;
    char pad1DA[2];
    float position;
    char pad1E0[0x70];
    Vec points[38];
    int index;
};
extern "C" int fn_27_2249E0(Stage*);
extern "C" const float lbl_46_rodata_0[];
extern "C" void fn_46_3CD4(Stage* self) {
    const float* p = lbl_46_rodata_0;
    if (fn_27_2249E0(self)) {
        Bounds* bounds = self->bounds;
        if (bounds) {
            float value = bounds->right - (self->position - bounds->left);
            if (value < p[0]) value = p[0];
            switch (self->state) {
            case 0:
                if (self->index == 36) self->index = 0;
                else if (value > p[38]) self->index = 0;
                goto copy;
            case 1:
                if (self->index == 36) self->index = 4;
                else if (value > p[39]) self->index = 4;
                goto copy;
            case 2: if (value > p[40]) self->index = 8; goto copy;
            case 3: if (value > p[41]) self->index = 12; goto copy;
            case 4: if (value > p[42]) self->index = 12; goto copy;
            case 5: if (value > p[43]) self->index = 16; goto copy;
            case 6: if (value > p[44]) self->index = 20; goto copy;
            case 7: if (value > p[45]) self->index = 20; goto copy;
            case 8: if (value > p[44]) self->index = 24; goto copy;
            case 9: if (value > p[40]) self->index = 24; goto copy;
            case 10:
                if (value > p[45]) self->index = 28;
                else if (value > p[46]) self->index = 16;
                goto copy;
            case 11:
                if (value > p[47]) self->index = 32;
                else if (value > p[48]) self->index = 16;
                goto copy;
            case 12: if (value > p[39]) self->index = 28; goto copy;
            case 13: if (value > p[47]) self->index = 32; goto copy;
            case 14: if (value > p[49]) self->index = 16; goto copy;
            case 15: goto copy;
            default: break;
            }
            return;
        copy:
            if (self->index != 36) {
                self->output[0] = self->points[self->index];
                self->output[1] = self->points[self->index + 1];
                self->output[2] = self->points[self->index + 2];
                self->output[3] = self->points[self->index + 3];
            }
        }
    }
}