#pragma force_active on
struct PeachState {
    unsigned char pad[8];
    int flags;
};

extern "C" int* fn_103_F774(PeachState* state, int index) {
    int offset = (state->flags >> 26) + index;
    if (offset >= 20) {
        offset -= 20;
    }
    return reinterpret_cast<int*>(reinterpret_cast<char*>(state) + 12 + offset * 4);
}
