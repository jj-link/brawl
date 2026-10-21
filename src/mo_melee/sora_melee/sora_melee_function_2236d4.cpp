#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct Stage {
    char pad0[0xBC];
    Vec3f *unkBC;
    char padC0[2];
    u8 unkC2;
} Stage;

extern const float lbl_27_rodata_33D8;

extern "C" void getPokeTrainerPos__5StageFP5Vec3fP5Vec3fUl(Stage *this_, Vec3f *arg0, Vec3f *arg1, u32 arg2)
{
    float z = lbl_27_rodata_33D8;
    arg0->z = z;
    arg0->y = z;
    arg0->x = z;
    arg1->z = z;
    arg1->y = z;
    arg1->x = z;

    switch (this_->unkC2) {
    case 0: {
        u32 i = (u32)(u8)arg2 * 2;
        Vec3f *p = (Vec3f *)((char *)this_->unkBC + i * 12);
        arg0->x = p->x;
        arg0->y = p->y;
        arg0->z = p->z;
        Vec3f *q = (Vec3f *)((char *)this_->unkBC + (i + 1) * 12);
        arg1->x = q->x;
        arg1->y = q->y;
        arg1->z = q->z;
        return;
    }
    case 1: {
        u32 off = arg2 * 12;
        Vec3f *p = (Vec3f *)((char *)this_->unkBC + off);
        arg0->x = *(float *)((char *)this_->unkBC + off);
        arg0->y = p->y;
        arg0->z = p->z;
        Vec3f *q = (Vec3f *)((char *)this_->unkBC + off);
        arg1->x = *(float *)((char *)this_->unkBC + off);
        arg1->y = q->y;
        arg1->z = q->z;
        return;
    }
    }
}
