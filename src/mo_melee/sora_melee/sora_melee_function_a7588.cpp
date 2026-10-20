#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

struct FlagBlock {
    u16 unk0;
    u16 flags;
};

struct FlagHolder {
    FlagBlock* block;
};

extern "C" {
bool fn_27_A7588(FlagHolder* holder, u32 mask)
{
    return (holder->block->flags & mask) != 0;
}
}
