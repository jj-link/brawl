#pragma force_active on
struct Flags {
    unsigned char b7 : 1;
    unsigned char b6 : 1;
    unsigned char b5 : 1;
    unsigned char b4 : 1;
    unsigned char b3 : 1;
    unsigned char b2 : 1;
    unsigned char b1 : 1;
    unsigned char b0 : 1;
};

union FlagByte {
    Flags bits;
    unsigned char raw;
};

struct Object {
    unsigned char pad[0x75];
    FlagByte flags;
};

extern "C" int fn_80134344(void* obj, int type) {
    Object* self = (Object*)obj;
    int result = 0;
    if (type == 0xFF &&
        (self->flags.bits.b6 == 1 || self->flags.bits.b7 == 1 ||
         self->flags.bits.b5 == 1 || self->flags.bits.b4 == 1 ||
         self->flags.bits.b3 == 1 || self->flags.bits.b1 == 1 ||
         self->flags.bits.b2 == 1 || self->flags.bits.b0 == 1)) {
        result = 1;
    } else {
        switch (type) {
        case 0: result = self->flags.bits.b6; break;
        case 3: result = self->flags.bits.b7; break;
        case 1: result = self->flags.bits.b5; break;
        case 2: result = self->flags.bits.b4; break;
        case 5: result = self->flags.bits.b3; break;
        case 7: result = self->flags.bits.b1; break;
        case 4: result = self->flags.bits.b2; break;
        case 6: result = self->flags.bits.b0; break;
        }
    }
    return result;
}
