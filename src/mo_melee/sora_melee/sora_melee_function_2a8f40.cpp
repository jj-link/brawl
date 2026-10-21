#pragma force_active on

typedef unsigned int u32;

struct Entry {
    int id;
    int unk4;
    float value;
    int unkC;
};

struct Entries {
    char pad[12];
    Entry* entries;
    u32 count;
};

extern "C" float fn_27_2AB504(void*, int, float);
extern "C" int fn_803F86E4(void*, const char*, ...);
extern "C" void fn_803FC984();

extern char __files[];
extern const char lbl_27_data_7908C[];
extern float lbl_27_rodata_5D5C;

extern "C" float fn_27_2A8F40(void* self, Entries* data, u32* bits) {
    float total = lbl_27_rodata_5D5C;

    for (u32 i = 0; i < data->count; ++i) {
        Entry* entry = &data->entries[i];
        int id = entry->id;

        if (id == -1)
            break;

        if (id == 2001)
            id = 64;

        bool valid = false;
        if (id >= 0 && id < 178)
            valid = true;

        if (valid) {
            if ((u32)id >= 178) {
                fn_803F86E4(__files + 0xA0, lbl_27_data_7908C);
                fn_803FC984();
            }

            if (!(bits[(u32)id >> 5] & (1 << (id & 31))))
                continue;
        }

        total += fn_27_2AB504(self, id, entry->value);
    }

    return total;
}
