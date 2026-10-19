#pragma force_active on
struct StBattleObj {
    char pad[0x6c];
    unsigned char flags;
};

extern "C" void fn_42_764(StBattleObj *self)
{
    self->flags |= 0x8;
}
