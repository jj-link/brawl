#pragma force_active on

extern "C" int fn_800B61C0(void*);
extern "C" void fn_800B5854(void*, int, int, int, int);

struct Obj {
    char pad0_48[0x48];
    int m48;
    int m4C;
    int m50;
    int m54;
    char pad58_6C[0x14];
    int m6C;
    char pad70_F0[0x80];
    void* mF0;
};

extern "C" void fn_800EB564(Obj* self) {
    switch (self->m6C) {
    case 1:
        if (fn_800B61C0(self->mF0)) {
            self->m6C = 3;
        }
        break;
    case 2: {
        int* p = (int*)self;
        for (int i = 0; i < 4; i++) {
            if (p[0x12 + i] == 0) {
                fn_800B5854(self->mF0, 2, 0x13, 1, 0);
                self->m6C = 3;
                break;
            }
        }
        break;
    }
    case 3: {
        int count = 0;
        if (self->m48 > 0) count++;
        if (self->m4C > 0) count++;
        if (self->m50 > 0) count++;
        if (self->m54 > 0) count++;
        if (count == 4) {
            fn_800B5854(self->mF0, 1, 0x13, 1, 0);
            self->m6C = 2;
        }
        break;
    }
    }
}