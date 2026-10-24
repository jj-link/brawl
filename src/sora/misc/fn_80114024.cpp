#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Src {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct Dst {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 bit80 : 1;
    u8 unkDrest : 7;
};

extern "C" {
void* fn_80111B70(void*, void*);

s32 fn_80114024(struct Src* arg0, struct Dst* arg1) {
    s32 ret = 0;
    void* temp = fn_80111B70((void*)arg0->unk8, (void*)arg0->unk0);
    if (temp != 0) {
        s32 a;
        s32 b;
        ret = 1;
        b = arg0->unk8;
        a = arg0->unk4;
        arg1->unk0 = (s32)temp;
        arg1->unk4 = a;
        arg1->unk8 = b;
        arg1->unkC = 0;
        arg1->bit80 = 0;
    } else {
        arg1->unk0 = 0;
        arg1->unk4 = 0;
        arg1->unk8 = 0;
        arg1->unkC = 0;
    }
    return ret;
}
}
