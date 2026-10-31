#pragma force_active on

extern "C" const float lbl_805A1DC8;
extern "C" const float lbl_805A1DD0;
extern "C" const float lbl_805A1DD4;
extern "C" const float lbl_805A1DD8;

struct Vec3 {
    float x;
    float y;
    float z;
};

struct State {
    unsigned char pad0[0x258];
    float timer0;
    float timer1;
    float timer2;
    float timer3;
    float timer4;
    float timer5;
    int flags;
};

extern "C" void fn_8009D564(void* arg0, int arg1, const Vec3* arg2) {
    State* state = (State*)arg0;

    switch (arg1) {
    case 1:
        if (!(state->flags & 1)) {
            state->timer5 = lbl_805A1DC8;
        }
        state->timer0 = lbl_805A1DC8;
        state->flags |= 1;
        break;
    case 2:
        if (!(state->flags & 2) || !(state->timer1 < lbl_805A1DD0)) {
            state->timer1 = lbl_805A1DC8;
            state->flags |= 2;
        }
        break;
    case 3:
        if (!(state->flags & 4) || !(state->timer2 < lbl_805A1DD0)) {
            state->timer2 = lbl_805A1DC8;
            state->flags |= 4;
        }
        break;
    case 4:
        if (!(state->flags & 8) || !(state->timer3 < lbl_805A1DD4)) {
            state->timer3 = lbl_805A1DC8;
            state->flags |= 8;
        }
        break;
    case 5:
        if (!(state->flags & 0x10) || !(state->timer4 < lbl_805A1DD8)) {
            state->timer4 = lbl_805A1DC8;
            state->flags |= 0x10;
        }
        break;
    }

    unsigned char* p = (unsigned char*)arg0;
    int i = 0;
    for (; i < 12; i += 3) {
        if (*(int*)(p + 0x38) == 0) {
            *(int*)(p + 0x38) = arg1;
            float x = arg2->x;
            float y = arg2->y;
            *(float*)(p + 0x2C) = x;
            float z = arg2->z;
            *(float*)(p + 0x30) = y;
            *(float*)(p + 0x34) = z;
        }
        if (*(int*)(p + 0x48) == 0) {
            *(int*)(p + 0x48) = arg1;
            float x = arg2->x;
            float y = arg2->y;
            *(float*)(p + 0x3C) = x;
            float z = arg2->z;
            *(float*)(p + 0x40) = y;
            *(float*)(p + 0x44) = z;
        }
        if (*(int*)(p + 0x58) == 0) {
            *(int*)(p + 0x58) = arg1;
            float x = arg2->x;
            float y = arg2->y;
            *(float*)(p + 0x4C) = x;
            float z = arg2->z;
            *(float*)(p + 0x50) = y;
            *(float*)(p + 0x54) = z;
        }
        if (*(int*)(p + 0x68) == 0) {
            *(int*)(p + 0x68) = arg1;
            float x = arg2->x;
            float y = arg2->y;
            *(float*)(p + 0x5C) = x;
            float z = arg2->z;
            *(float*)(p + 0x60) = y;
            *(float*)(p + 0x64) = z;
        }
        p += 0x40;
    }
    if (i < 12) {
        return;
    }
}
