#pragma force_active on

typedef unsigned int u32;

struct Item;

struct Container {
    char pad[0xE4];
    u32 count;
    u32 unkE8;
    int* array;
};

extern "C" int fn_801ABE70(Container* self, u32 pos, Item* item);
extern int lbl_8059E950;

extern "C" int fn_801B4EB4(Container* self, u32 idx, Item* item) {
    int val = lbl_8059E950;
    int result = fn_801ABE70(self, idx, item);
    if (result) {
        for (u32 n = self->count - 1; n > idx; --n) {
            self->array[n] = self->array[n - 1];
        }
        self->array[idx] = val;
    }
    return result;
}
