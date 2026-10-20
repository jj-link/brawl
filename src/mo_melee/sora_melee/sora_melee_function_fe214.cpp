#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    int unk8;
} Foo;

extern "C" int fn_27_FE214(Foo* p) {
    return p->unk8 >> 26;
}
