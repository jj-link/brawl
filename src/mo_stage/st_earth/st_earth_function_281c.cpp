#pragma force_active on
typedef unsigned char u8;

struct Entry {
    u8 type;
    u8 padding01[8];
    u8 state;
    u8 padding0A[0x4E];
};

struct Config {
    u8 padding00[0x3C];
    u8 count;
};

struct Object {
    u8 padding00[0x9C];
    Config* config;
    u8 paddingA0[0x1D8];
    Entry* entries;
};

extern "C" int fn_66_281C(Object* object) {
    Entry* entries = object->entries;
    if (entries == 0)
        return 0;

    Config* config = object->config;
    if (config == 0)
        return 0;

    Entry* entry;
    u8 i;
    u8 count = config->count;
    int result = 0;

    for (i = 0; i != count; ++i) {
        entry = &entries[i];
        if (entry->type == 3) {
            switch (entry->state) {
            case 0:
            case 1:
            case 2:
                ++result;
                break;
            }
        }
    }

    return result;
}
