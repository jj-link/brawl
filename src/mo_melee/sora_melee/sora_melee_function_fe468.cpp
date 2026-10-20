#pragma force_active on
struct FooStruct {
    int unk0;
    int unk4;
    unsigned int unk8;
};

extern "C" {
int fn_27_FE468(FooStruct* p) {
    return (int)(((p->unk8 >> 27) & 7) << 29) >> 30;
}
}
