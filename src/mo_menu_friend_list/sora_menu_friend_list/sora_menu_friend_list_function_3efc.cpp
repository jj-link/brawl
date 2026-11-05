#pragma force_active on
typedef unsigned char u8;
typedef unsigned long long u64;

extern "C" {
void fn_14_A18(void* self);
int fn_800343CC(void* p, u64 id, void* info);

int fn_14_3EFC(void* self) {
    u8* s = (u8*)self;
    int state = *(int*)(s + 0x24c4);
    if (*(int*)(s + 0x2b0) != 1) {
        void* p = *(void**)(s + 0x2a2c);
        state = 0;
        if (p != 0) {
            if (s[0x2300] == 0xff) {
                u8 info[80];
                if (fn_800343CC(p, *(u64*)(s + 0x2308), info) == 0) {
                    state = 2;
                }
            }
        } else {
            state = 1;
        }
        if (state == 0) {
            state = 2;
        } else {
            if (state == 1) {
                *(int*)(s + 0x2a34) = 0x15;
            } else {
                *(int*)(s + 0x2a34) = 0x16;
            }
            state = 1;
            s[0x2300] = 0;
        }
        if (s[0x40] == 0) {
            fn_14_A18(self);
        }
    }
    return state;
}
}
