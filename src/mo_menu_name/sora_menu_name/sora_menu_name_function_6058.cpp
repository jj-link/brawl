#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);
extern "C" int fn_16_4C90(void*, const void*, int, const void*, int);

extern "C" int fn_16_6058(unsigned char* self) {
    if (*(int*)(self + 0x478) < 0)
        return 0x18;

    void* task = *(void**)(self + 0x45c);
    int state;

    if (*(int*)((unsigned char*)task + 0x104) != 3) {
        state = 0;
    } else {
        state = 2;
        if (*(unsigned char*)((unsigned char*)task + 0x100) != 0)
            state = 1;
        exit__6gfTaskFv(task);
        *(int*)(self + 0x45c) = 0;
    }

    if (state == 0)
        return *(int*)(self + 0x9c);

    if (state == 1) {
        int bit = (self[0x40c] >> 7) & 1;
        fn_16_4C90(self, self + 0x40e, ((bit - 1) == 0), self + 0x41a, 1);
        return 0x13;
    }

    return 0x10;
}
