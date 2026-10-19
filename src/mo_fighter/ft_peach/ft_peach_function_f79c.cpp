#pragma force_active on
struct PeachField {
    unsigned int padding[2];
    unsigned int : 12;
    unsigned int value : 6;
    unsigned int : 14;
};

extern "C" void fn_103_F79C(PeachField* object, unsigned int value) {
    object->value = value;
}
