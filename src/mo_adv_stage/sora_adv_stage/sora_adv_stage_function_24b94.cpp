#pragma force_active on
struct FlagHolder {
    int pad[2];
    unsigned int flags;
};

extern "C" void fn_40_24B94(FlagHolder* self) {
    self->flags &= ~0x02000000u;
}
