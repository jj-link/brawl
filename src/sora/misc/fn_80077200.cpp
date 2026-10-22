#pragma force_active on
extern "C" {
extern void* fn_801B77F8(void*);
extern void fn_801B818C(void*, int, void*);

void fn_80077200(unsigned char* self, int a, int mode) {
    if (self[0x6EF]) {
        switch (mode) {
        case 0:
            fn_801B818C(fn_801B77F8(self), 0, self + 0x728);
            self[0xB90] |= 1;
            break;
        case 1:
            fn_801B818C(fn_801B77F8(self), 0, self + 0xA48);
            self[0xB90] |= 2;
            break;
        }
    }
}
}
