#pragma force_active on

extern "C" const float lbl_27_rodata_DA8;

struct Condition {
    int kind;
    float a;
    float b;
};

struct Object {
    int state;
    Condition conditions[2];
    unsigned char flag1;
    unsigned char flag2;
};

static inline bool test(const Condition* condition, int kind, float a, float b) {
    switch (kind) {
    case 1:
        return true;
    case 2:
        return a <= condition->a;
    case 3:
        return b <= condition->b;
    case 0:
        if (a <= lbl_27_rodata_DA8 && b >= lbl_27_rodata_DA8)
            return true;
        else
            return false;
    default:
        return false;
    }
}

extern "C" bool fn_27_B1468(Object* self, int arg, float a, float b) {
    if (self->flag2 == 1)
        return true;

    if (arg == 0) {
        if (self->flag1 == 1 || self->state == 1)
            return true;

        for (int i = 0; i < 2; ++i) {
            int kind = self->conditions[i].kind;
            if (kind != -1) {
                if (test(&self->conditions[i], kind, a, b) == true)
                    return true;
            }
        }
    }

    return false;
}
