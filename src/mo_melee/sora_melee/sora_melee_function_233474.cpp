#pragma force_active on
struct Data {
    unsigned char pad0[0x65];
    unsigned char count;
    unsigned char pad1[2];
    unsigned char enabled;
    unsigned char pad2[0xB];
    unsigned char extra;
};

struct Entry {
    unsigned char pad[0x90];
    Data* data;
};

struct Object {
    unsigned char pad[0x4C];
    Entry** entries;
};

extern "C" int fn_27_233474(Object* object, int index, int value) {
    Data* data = object->entries[index]->data;
    int result = 1;
    if (value >= data->count - 1) {
        if (data->enabled) {
            result = data->extra + 1;
        }
    } else {
        result = 0;
    }
    return result;
}
