#pragma force_active on
extern "C" int fn_40_3EDB0(void*, int*, int);

struct Data {
    int values[20];
    int count;
    int value54;
    int value58;
    int count2;
    int value60;
    int value64;
};

struct Entry {
    char pad[0x40];
    int value;
    char rest[0x68];
};

struct Sub {
    char pad[0xa8];
    int out[40];
    int count;
    int value;
};

struct Obj {
    Entry entries[10];
    char pad0[0x40];
    int entryCount;
    char pad1[0x274];
    Sub sub;
    char pad2[0xa8];
    int out2[40];
    int outCount2;
    int outValue2;
    char pad3[0xc];
    int index;
    char pad4[0x1c];
    Data* data;
};

inline int findEntry(int result, int index, Entry* entry, int count)
{
    for (int n = count; n > 0; n--) {
        if (result == entry->value)
            return index;
        entry++;
        index++;
    }
    return -1;
}

extern "C" void fn_40_3E58C(Obj* self)
{
    int value;
    int offset;
    Sub* p;
    Sub* sub;
    int i;

    sub = &self->sub;
    p = sub;
    i = 0;
    offset = 0;

    while (i < self->data->count) {
        fn_40_3EDB0(self, &value, *(int*)((char*)self->data + offset));
        offset += 4;
        i++;
        p->out[0] = value;
        p = (Sub*)((char*)p + 4);
    }

    sub->count = self->data->count;
    int result = fn_40_3EDB0(self, &value, self->data->value60);
    sub->value = value;

    self->index = findEntry(result, 0, self->entries, self->entryCount);
    if (self->data->count2 > 0) {
        fn_40_3EDB0(self, &value, self->data->value54);
        self->out2[0] = value;
    }

    self->outCount2 = self->data->count2;
    fn_40_3EDB0(self, &value, self->data->value64);
    self->outValue2 = value;
}
