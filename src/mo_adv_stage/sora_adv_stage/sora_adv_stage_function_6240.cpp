#pragma force_active on
extern "C" void* getInstance__9itManagerFv();
extern "C" void fn_27_2AA7AC(void* mgr, void* pos, int a, int b, int c, int d, int e);

struct Pair {
    unsigned int x;
    unsigned int y;
};

struct Holder {
    char pad[0x588];
    Pair pos;
};

extern "C" void fn_40_6240(Holder* self, int a, int b) {
    Pair tmp = self->pos;
    fn_27_2AA7AC(getInstance__9itManagerFv(), &tmp, a, b, -1, -1, -1);
}
