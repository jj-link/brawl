// Only fields used by these original callbacks are reconstructed.
struct NessSupportValues {
    unsigned char unknown[8];
    unsigned int value08;
    unsigned int value0C;
    unsigned int value10;
    unsigned short value14;
    unsigned short value16;
};

extern "C" unsigned int fn_101_16104(NessSupportValues* object) {
    return object->value10;
}
extern "C" unsigned int fn_101_1610C(NessSupportValues* object) {
    return object->value10;
}
extern "C" unsigned int fn_101_16114(NessSupportValues* object) {
    return object->value10;
}
extern "C" unsigned int fn_101_1611C(NessSupportValues* object) {
    return object->value14;
}
extern "C" unsigned int fn_101_16124(NessSupportValues* object) {
    return object->value08;
}
extern "C" unsigned int fn_101_1612C(NessSupportValues* object) {
    return object->value16;
}
extern "C" unsigned int fn_101_16134(NessSupportValues* object) {
    return object->value0C;
}
extern "C" void fn_101_1613C(NessSupportValues* object, unsigned int value) {
    object->value16 = value;
}
extern "C" void fn_101_16144(NessSupportValues* object, unsigned int value) {
    object->value14 = value;
}
extern "C" void fn_101_1614C(NessSupportValues* object, unsigned int value) {
    object->value0C = value;
}
extern "C" void fn_101_16154(NessSupportValues* object, unsigned int value) {
    object->value08 = value;
}
extern "C" void fn_101_1615C(NessSupportValues* object, unsigned int value) {
    object->value10 = value;
}
extern "C" void fn_101_16164(NessSupportValues* object, unsigned int value) {
    object->value10 = value;
    object->value0C = value;
    object->value08 = value;
}
