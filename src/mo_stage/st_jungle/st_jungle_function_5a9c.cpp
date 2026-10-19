#pragma force_active on
struct St51Obj {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" int fn_51_5A9C(St51Obj *p)
{
    return p->unk8 >> 30;
}
