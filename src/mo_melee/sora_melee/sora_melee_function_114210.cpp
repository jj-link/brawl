#pragma force_active on

struct Entry {
    int value;
    int other;
};

struct Object {
    unsigned char pad0[0xA];
    unsigned char index;
    unsigned char padB[3];
    unsigned char flags;
    unsigned char padF[0x21];
    Entry entries[5];
    unsigned char pad58[4];
    int state;
};

extern "C" int fn_27_114210(Object* self) {
    if (self->flags & 1) {
        switch (self->entries[self->index].value) {
        case 29: return 29;
        case 30: return 31;
        case 31: return 33;
        }
    } else {
        switch (self->state) {
        case 14:
        case 15:
            switch (self->entries[self->index].value) {
            case 13: return 14;
            case 14: return 15;
            }
            break;
        case 3:
        case 4:
            switch (self->entries[self->index].value) {
            case 3: return 3;
            case 24: return 4;
            }
            break;
        }
    }
    return self->state;
}
