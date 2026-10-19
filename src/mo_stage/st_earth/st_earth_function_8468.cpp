#pragma force_active on
struct EarthObject {
    unsigned char padding[0x150];
    unsigned char state;
    unsigned char padding151[0x10];
    unsigned char value;
};

extern "C" void fn_66_8468(EarthObject* object, unsigned char value) {
    if (static_cast<int>(object->state) == 1) {
        object->value = value;
        object->state = 0x10;
    }
}
