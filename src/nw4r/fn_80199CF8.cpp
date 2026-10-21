#pragma force_active on

struct Obj {
    int pad[4];
    int mCount;
    unsigned short* mArray;
};

extern "C" void fn_8019DA5C(Obj* self, unsigned int mask, int flag);

extern "C" void fn_80199CF8(Obj* self) {
    int i;
    for (i = 0; i < self->mCount; i++) {
        self->mArray[i] = 0x8000;
    }
    fn_8019DA5C(self, 4, 0);
}
