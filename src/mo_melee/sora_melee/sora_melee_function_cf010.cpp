#pragma force_active on
typedef struct {
    int a;
    int b;
    int field;
} SomeStruct;

extern "C" int fn_27_CF010(SomeStruct* p) {
    return p->field >> 26;
}
