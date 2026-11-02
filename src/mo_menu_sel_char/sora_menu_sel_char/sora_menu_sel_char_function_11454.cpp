#pragma force_active on
struct Obj {
    char pad[0x1b8];
    int value;
    char pad2[0x2c];
    int field1e8;
    int field1ec;
    int field1f0;
};

extern "C" void fn_10_11454(Obj* obj, int value) {
    switch (value) {
    case 3:
        value = 3;
        obj->field1ec = 0;
        break;
    case 4:
        value = 3;
        obj->field1ec = 0;
        break;
    case 14:
        value = 14;
        obj->field1e8 = 0;
        break;
    case 15:
        value = 14;
        obj->field1e8 = 1;
        break;
    case 27:
        value = 27;
        obj->field1f0 = 0;
        break;
    case 28:
        value = 27;
        obj->field1f0 = 1;
        break;
    case 29:
        value = 27;
        obj->field1f0 = 2;
        break;
    case 30:
        value = 27;
        obj->field1f0 = 3;
        break;
    }
    obj->value = value;
}
