#pragma force_active on
extern "C" {
void exit__6gfTaskFv(void* task);
unsigned char fn_800BA3D8(void* a, void* b);
void* fn_800BEEB8(int a1, int a2, int a3, void* a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
}

extern "C" void fn_40_47A70(unsigned char* self) {
    if (self[0x1421] != 0) {
        unsigned char* p = *(unsigned char**)(self + 0x1888);
        int r31 = *(int*)(self + 0x1560);
        int r30 = *(int*)(p + 4);
        int b = fn_800BA3D8(self + 0x100, p);
        int b1b0 = *(int*)(self + 0x1B0);
        void* task = fn_800BEEB8(1, r30, 0xC, self + 0x147C, r31, *(int*)(self + 0x143C), 0, *(int*)(self + 0x1AC), b1b0, 0, 0, b & 0xFF);
        void* old = *(void**)(self + 0x188C);
        if (old != 0) {
            exit__6gfTaskFv(old);
        }
        *(void**)(self + 0x188C) = task;
    }
}
