#pragma force_active on
extern "C" {
extern float lbl_41_rodata_C90[];
extern char lbl_41_data_644[];
extern char lbl_41_data_6A8[];
}

struct Vec2 {
    float x, y;
};

struct Enemy {
    char pad0[8];
    int unk08;
    char padC[0x40];
    float unk4C;
    char pad50[0x24];
    int unk74;
    char pad78[4];
    float unk7C;
};

struct Modules {
    char pad0[0x7C];
    void* area;
};

struct Accesser {
    char pad0[0xD8];
    Modules* modules;
};

extern "C" {
bool fn_41_1AE7C(Enemy*);
int fn_41_1AE30(int);
float fn_41_15A00(float, Vec2*);
void fn_41_1AF9C(Enemy*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Enemy* fn_41_15FD4(void*, int);

bool fn_41_1C414(Enemy* self, Accesser* acc, Vec2* pos) {
    float* data = lbl_41_rodata_C90;

    if (fn_41_1AE7C(self) == 1)
        return true;

    if (fn_41_1AE30(self->unk08) == 0)
        return false;

    if (fn_41_1AE30(self->unk08) == 1) {
        if (self->unk08 == 2) {
            Vec2 v = *pos;
            float angle = fn_41_15A00(data[12], &v);
            float dir;

            if (angle > data[14] && angle < data[15])
                dir = data[0];
            else
                dir = data[12];

            if (data[12] == dir) {
                if (data[12] == self->unk7C && self->unk4C < data[3]) {
                    fn_41_1AF9C(self);
                    self->unk4C = -self->unk4C;
                }
                if (data[0] == self->unk7C && self->unk4C > data[3]) {
                    fn_41_1AF9C(self);
                    self->unk4C = -self->unk4C;
                }
            } else {
                if (data[12] == self->unk7C && self->unk4C > data[3]) {
                    fn_41_1AF9C(self);
                    self->unk4C = -self->unk4C;
                }
                if (data[0] == self->unk7C && self->unk4C < data[3]) {
                    fn_41_1AF9C(self);
                    self->unk4C = -self->unk4C;
                }
            }
        }
        return false;
    }

    if (fn_41_1AE30(self->unk08) == 2) {
        void* area = __dynamic_cast(
            acc->modules->area, 0, lbl_41_data_644, lbl_41_data_6A8, 1);
        return fn_41_1C414(fn_41_15FD4(area, self->unk74), acc, pos);
    }

    return true;
}
}
