#pragma force_active on
extern "C" {
void fn_800B753C(void*, float);
unsigned int fn_800B63B8(void*);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
extern char lbl_24_data_128[];
extern char lbl_24_data_13C[];
extern float lbl_24_rodata_0;
extern float lbl_24_rodata_4;
}

struct S {
    char pad[0x1C8];
    void* objA;
    void* objB;
    char pad2[4];
    unsigned int state;
    int cnt;
};

extern "C" void fn_24_204(S* s) {
    switch (s->state) {
    case 1:
        s->state = 2;
        break;
    case 2:
        fn_800B753C(s->objA, lbl_24_rodata_0);
        setUpdateRate__16gfModelAnimationFf(*(void**)((char*)s->objA + 0x14), lbl_24_rodata_4);
        changeAnimN__8MuObjectFPCc(s->objB, lbl_24_data_128);
        fn_800B753C(s->objB, lbl_24_rodata_0);
        setUpdateRate__16gfModelAnimationFf(*(void**)((char*)s->objB + 0x14), lbl_24_rodata_4);
        s->state = 3;
        break;
    case 3:
        if (fn_800B63B8(s->objB) == 1) s->state = 4;
        break;
    case 4:
        setUpdateRate__16gfModelAnimationFf(*(void**)((char*)s->objB + 0x14), lbl_24_rodata_0);
        s->state = 5;
        s->cnt = 0;
        break;
    case 5:
        s->state = 6;
        break;
    case 6:
        if (s->cnt >= 0x4B0) s->state = 7;
        break;
    case 7:
        s->state = 8;
        break;
    case 8:
        changeAnimN__8MuObjectFPCc(s->objB, lbl_24_data_13C);
        fn_800B753C(s->objB, lbl_24_rodata_0);
        setUpdateRate__16gfModelAnimationFf(*(void**)((char*)s->objB + 0x14), lbl_24_rodata_4);
        s->state = 9;
        break;
    case 9:
        if (fn_800B63B8(s->objB) == 1) s->state = 0xA;
        break;
    case 0xA:
        setUpdateRate__16gfModelAnimationFf(*(void**)((char*)s->objB + 0x14), lbl_24_rodata_0);
        s->state = 0xB;
        break;
    case 0xC:
        s->state++;
        break;
    }
    s->cnt++;
}