#pragma force_active on
struct FtPikminEntry {
    unsigned char pad[9];
    signed char value;
    unsigned char rest[2];
};

class FtPikminProvider {
public:
    virtual void slot00();
    virtual void slot04();
    virtual int slot08();
    int unk04;
    FtPikminEntry* entries;
    int index;
};

extern "C" int fn_113_242C8(FtPikminProvider* self) {
    if (self->slot08() == 0) {
        self->index = -1;
        return 0;
    }
    self->index = self->entries[self->index].value;
    return 1;
}
