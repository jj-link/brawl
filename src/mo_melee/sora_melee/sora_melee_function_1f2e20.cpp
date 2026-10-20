#pragma force_active on
struct Node {
    unsigned char pad[0x3e];
    unsigned char mask;
    unsigned char pad3f;
    unsigned int flags;
};

extern "C" bool fn_27_1F2E20(Node* self, int index) {
    if (self->flags & 0x800) {
        if (index < 0 || index >= 8 || (self->mask & (1 << index))) {
            return true;
        }
    }
    return false;
}
