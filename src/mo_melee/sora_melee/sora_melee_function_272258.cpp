#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Item {
    u8 pad[0x10];
    u32 key;
    u8 pad2[0x8];
    u8 flag;
};

struct Node {
    u32 pad0;
    struct Node* next;
    struct Item* item;
};

struct List {
    u32 pad0;
    struct Node* first;
    u32 pad1;
    struct Node* cur;
    u32 count;
    u32 pad2;
    u8 flag;
};

extern "C" void fn_27_272258(struct List* self, u8 val, u32 key)
{
    u8 found = 0;
    u32 i;
    u32 n = self->count;

    self->cur = self->first;
    for (i = 0; i < n; i++) {
        if (key == self->cur->item->key) {
            self->cur->item->flag = val;
        }
        if (self->cur->item->flag != 0) {
            found = 1;
        }
        self->cur = self->cur->next;
    }
    self->flag = found;
}
