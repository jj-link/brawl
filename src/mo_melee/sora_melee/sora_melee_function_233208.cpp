#pragma force_active on
struct Inner {
    unsigned char _pad[0x7c];
    unsigned short kind;
};

struct Mid {
    unsigned char _pad[0x90];
    Inner* inner;
};

struct Container {
    unsigned char _pad[0x4c];
    Mid** entries;
    unsigned int count;
};

extern "C" int fn_40_13840(void* p);

extern "C" int fn_27_233208(Container* self, unsigned short kind, int skip)
{
    unsigned int i = 0;
    while (i < self->count) {
        Mid* entry = self->entries[i];
        if (kind == entry->inner->kind) {
            if (skip == 0) {
                return fn_40_13840(self->entries[i]);
            }
            skip--;
        }
        i++;
    }
    return 0;
}
