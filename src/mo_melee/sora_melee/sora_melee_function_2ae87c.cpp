#pragma force_active on
struct FooObj {
    int unk0;
    int unk4;
};

extern "C" {
unsigned int fn_27_2AE87C(FooObj* p) {
    return (unsigned int)((int)p->unk4 >> 27) >> 31;
}
}
