#pragma force_active on
extern "C" {
typedef struct {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
} FlagsObj;

void fn_27_1A5888(FlagsObj *obj, unsigned int v) {
    obj->b = v;
}
}
