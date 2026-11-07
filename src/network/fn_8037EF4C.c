#pragma force_active on
typedef struct Object {
    char pad0[0x10];
    int field10;
    char pad14[0x8c];
    int fieldA0;
    char padA4[4];
    int fieldA8;
    char padAC[0x70];
    int field11C;
} Object;
extern Object *fn_8037C720();

int fn_8037EF4C(void) {
    Object *obj = fn_8037C720();
    int offset;
    if (obj == 0) return 0;
    if (obj->field10 < 9) return 0;
    offset = obj->field11C;
    if (offset >= obj->fieldA8) return 0;
    return obj->fieldA0 + offset;
}