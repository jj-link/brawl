#pragma force_active on

struct Vec2 {
    float x, y;
};

struct Enemy {
    char pad0[8];
    int unk08;
    char padC[0x68];
    int unk74;
    char pad78[0x3C];
    Vec2 unkB4;
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
extern char lbl_41_data_644[];
extern char lbl_41_data_6A8[];
extern float lbl_41_rodata_C9C;

bool fn_41_1AE7C(Enemy*);
int fn_41_1AE30(int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Enemy* fn_41_15FD4(void*, int);
void fn_41_1BEA8(Vec2*, const Vec2*);

bool fn_41_1C6E4(Enemy* self, Accesser* acc, int arg2) {
    if (fn_41_1AE7C(self) == 1)
        return true;

    if (fn_41_1AE30(self->unk08) == 0)
        return true;

    if (fn_41_1AE30(self->unk08) == 1)
        return false;

    if (fn_41_1AE30(self->unk08) == 2) {
        void* area = __dynamic_cast(
            acc->modules->area, 0, lbl_41_data_644, lbl_41_data_6A8, 1);
        Enemy* other = fn_41_15FD4(area, self->unk74);
        Vec2 v = { lbl_41_rodata_C9C, lbl_41_rodata_C9C };
        fn_41_1BEA8(&self->unkB4, &v);
        return fn_41_1C6E4(other, acc, arg2);
    }

    return true;
}
}
