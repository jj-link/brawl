#pragma force_active on
typedef unsigned char u8;

struct GameWatchAccesser {
    u8 prefix[0x14];
    int firstIndex;
};

extern "C" int fn_107_16970(GameWatchAccesser* self, void*, int index, int element) {
    int* row = ((int**)((u8*)self + ((index - self->firstIndex) << 2)))[8];
    return row[element];
}
