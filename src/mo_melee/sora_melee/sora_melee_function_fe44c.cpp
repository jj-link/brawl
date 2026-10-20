#pragma force_active on
struct S { int unk0[2]; int unk8; };

extern "C" int fn_27_FE44C(S* s)
{
    return s->unk8 >> 30;
}
