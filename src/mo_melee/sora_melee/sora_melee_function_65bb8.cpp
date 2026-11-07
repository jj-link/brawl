#pragma force_active on
struct Data {
    unsigned int w[7];
    unsigned short h[2];
    unsigned char b[11];
};
struct Object {
    char pad[0x24];
    Data data;
    char pad2[4];
    float value;
};
extern "C" void fn_27_65BB8(Object* obj, const Data* data, float value) {
    if (value < obj->value) {
        obj->data = *data;
        obj->value = value;
    }
}