#pragma force_active on
struct Entry { unsigned int value; char pad[0x2c]; };
struct Obj {
    char pad[0x194];
    Entry* entries;
    char pad2[4];
    unsigned int counts[24];
    unsigned int indices[24][50];
};
extern "C" int fn_80079410(Obj* obj, unsigned int value, unsigned int* out1, unsigned int* out2) {
    for (unsigned int i = 0; i < 24; i++) {
        for (unsigned int j = 0; j < obj->counts[i]; j++) {
            if (value == obj->entries[obj->indices[i][j]].value) {
                *out1 = i;
                *out2 = j;
                return 1;
            }
        }
    }
    return 0;
}