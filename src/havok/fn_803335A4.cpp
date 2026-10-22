#pragma force_active on

extern "C" {
const char* fn_8027C83C(void*);
int fn_80281AE8(const char*, const char*);
}

struct Entry {
    int unk0;
    const char* name;
    unsigned int id;
    void* object;

    const char* getName() {
        if (name != 0) {
            return name;
        }
        return object != 0 ? fn_8027C83C(object) : 0;
    }
};

struct Table {
    Entry* entries;
    int count;
};

extern "C" unsigned int fn_803335A4(
    Table* self, const char* name, unsigned int after)
{
    int i = 0;
    unsigned int id;

    do {
        if (after == 0 || i >= self->count) {
            break;
        }
        id = self->entries[i++].id;
    } while (id != after);

    for (; i < self->count; ++i) {
        if (fn_80281AE8(name, self->entries[i].getName()) == 0) {
            return self->entries[i].id;
        }
    }
    return 0;
}
