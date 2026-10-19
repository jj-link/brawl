#pragma force_active on
struct FriendList {
    char pad0[0x2B0];
    int state;
    char pad1[0x24C4 - 0x2B4];
    int result;
};

extern "C" int fn_14_75B8(FriendList* self) {
    if (self->state != 5) {
        return 0x12;
    }
    return self->result;
}
