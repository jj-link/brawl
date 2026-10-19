#pragma force_active on
struct SoraFriendListState {
    char m_pad0000[0x2b0];
    int m_state;
    char m_pad02b4[0x24c4 - 0x2b4];
    int m_value;
};

extern "C" int fn_14_8938(SoraFriendListState* self) {
    if (self->m_state != 2) {
        return 0x19;
    }
    return self->m_value;
}
