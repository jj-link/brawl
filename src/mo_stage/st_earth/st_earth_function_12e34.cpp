#pragma force_active on
struct Flags55 {
    unsigned char low4 : 4;
    unsigned char bit3 : 1;
};

struct Object {
    unsigned char pad[0x55];
    Flags55 flags;
};

struct Owner {
    unsigned char pad[0x160];
    Object* object;
};

extern "C" void fn_66_12E34(Owner* owner, int value) {
    if (owner->object == 0) {
        return;
    }
    owner->object->flags.bit3 = value;
}
