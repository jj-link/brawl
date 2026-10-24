#pragma force_active on
class gfModelAnimation {
public:
    void setUpdateRate(float);
};
class MuObject {
public:
    char pad[0x14];
    gfModelAnimation* anim;
    void changeAnimN(const char*);
};
extern "C" {
void fn_800B753C(MuObject*, float);
unsigned int fn_800B63B8(MuObject*);
extern char lbl_24_data_34C[];
extern char lbl_24_data_360[];
extern float lbl_24_rodata_18;
extern float lbl_24_rodata_1C;
}
struct T {
    char pad[0x48];
    MuObject* a;
    MuObject* b;
    char pad2[8];
    unsigned int state;
    int cnt;
};
extern "C" void fn_24_B9C(T* s) {
    switch (s->state) {
    case 1:
        fn_800B753C(s->a, lbl_24_rodata_18);
        s->a->anim->setUpdateRate(lbl_24_rodata_1C);
        s->state = 2;
        break;
    case 2:
        s->b->changeAnimN(lbl_24_data_34C);
        fn_800B753C(s->b, lbl_24_rodata_18);
        s->b->anim->setUpdateRate(lbl_24_rodata_1C);
        s->state = 3;
        s->cnt = 0;
        break;
    case 3:
        if (fn_800B63B8(s->b) == 1) s->state = 4;
        break;
    case 4:
        s->b->anim->setUpdateRate(lbl_24_rodata_18);
        s->state = 5;
        break;
    case 5:
        s->state = 6;
        s->cnt = 0;
        break;
    case 6:
        if (fn_800B63B8(s->a) == 1) s->state = 7;
        break;
    case 7:
        s->state = 8;
        break;
    case 8:
        s->b->changeAnimN(lbl_24_data_360);
        fn_800B753C(s->b, lbl_24_rodata_18);
        s->b->anim->setUpdateRate(lbl_24_rodata_1C);
        s->state = 9;
        break;
    case 9:
        if (fn_800B63B8(s->b) == 1) s->state = 10;
        break;
    case 10:
        s->b->anim->setUpdateRate(lbl_24_rodata_18);
        s->state = 11;
        break;
    case 12:
        s->state++;
        break;
    }
    s->cnt++;
}
