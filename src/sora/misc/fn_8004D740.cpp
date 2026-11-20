#pragma force_active on
struct Slot {
    unsigned char pad[0xE0];
    unsigned short value;
    unsigned char tail[0x42];
};
struct Group {
    unsigned char pad[0x28];
    Slot* slots;
};
inline int countSlots(Group* self) {
    int i;
    int count = 0;
    Slot* slot = self->slots;
    for (i = 0; i < 120; ++i) {
        if (slot[i].value) ++count;
    }
    return count;
}
extern "C" int fn_8004D740(Group* self) {
    return 120 - countSlots(self);
}