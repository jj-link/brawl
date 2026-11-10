#include <types.h>
#pragma force_active on

extern "C" int fn_80114A60(void*, void*);

struct Entry {
    u32 a, b, c;
    u8 d, e;
    u8 pad[2];
};

inline bool valid(Entry* p) {
    return p->a != 0 && p->b != 0 && p->c != 0;
}

extern "C" void fn_80137298(void* arg0, u32* arg1) {
    u8* base = (u8*)arg0;
    Entry* p = (Entry*)(base + 0x174);
    u32 i = 0;

    while (i < base[0x7D]) {
        if (valid(p)) {
            int equal = 0;
            if (p->a == *arg1)
                equal = 1;

            if (equal != 0 || fn_80114A60(p, arg1) != 0) {
                u8* q = base + i * 0x10;

                for (; i < base[0x7D] - 1; i++, q += 0x10) {
                    *(u32*)(q + 0x174) = *(u32*)(q + 0x184);
                    *(u32*)(q + 0x178) = *(u32*)(q + 0x188);
                    *(u32*)(q + 0x17C) = *(u32*)(q + 0x18C);
                    q[0x180] = q[0x190];
                    q[0x181] = q[0x191];
                }

                u8* last = base + (base[0x7D] - 1) * 0x10;
                *(u32*)(last + 0x174) = 0;
                *(u32*)(last + 0x178) = 0;
                *(u32*)(last + 0x17C) = 0;
                last[0x180] = 0;
                base[0x7D] = base[0x7D] - 1;
                return;
            }
        }

        p++;
        i++;
    }
}
