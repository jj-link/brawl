#pragma force_active on
struct Obj {
    int pad[3];
    unsigned int mC;
    int mCount;
    unsigned short* mArray;
};

extern "C" void fn_8019DA5C(Obj* self, unsigned int mask, int flag);

extern "C" void fn_801975EC(Obj* self) {
    for (int i = 0; i < self->mCount; i++) {
        self->mArray[i] = 0x8000;
    }
    fn_8019DA5C(self, 4, 0);
}
