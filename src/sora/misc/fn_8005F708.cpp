#pragma force_active on
struct ecMgr {
    char pad[0x81];
    unsigned char count;
    char pad2[2];
    unsigned long groups[4];
};

extern "C" void pushsetCurrentGroup__5ecMgrFUl(ecMgr* self, unsigned long arg0)
{
    unsigned char count = self->count;
    if (count < 2) {
        count++;
        self->count = count;
        self->groups[count] = arg0;
    }
}
