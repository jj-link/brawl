#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Flags {
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
};

struct Entry {
    u8 pad[0x1A];
    u8 type;
    u8 rest[0x25];
};

struct Node {
    u8 pad[0x54];
    Flags flags;
    u8 pad55;
    u8 flags56;
    u8 pad57;
    void* owner;
    void* context;
};

struct Stage {
    u8 pad[0x15C];
    u32 count;
    Entry* entries;
    Node* nodes;
    u8 pad168[8];
    u8 context;
};

extern "C" void fn_48_98E8(Stage*, u32, int);

extern "C" void fn_48_7DAC(Stage* stage) {
    u32 count = stage->count;
    Entry* entry = stage->entries;
    Node* node = stage->nodes;

    if (!count || !entry || !node)
        return;

    for (u32 i = 0; i < count; ++i, ++node, ++entry) {
        node->flags56 |= 0x80;
        node->flags.b6 = node->flags.b4 = node->flags.b7 = 0;
        node->context = &stage->context;
        node->flags.b3 = 1;
        node->owner = stage;

        if (entry->type == 3)
            fn_48_98E8(stage, i, 1);
    }
}
