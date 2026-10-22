#pragma force_active on
#include <types.h>

struct Key { u32 id; u8 pad[0xC]; };
struct Sub { Key* src; u32 count; u32* dst; };
struct S { u8 pad[4]; Sub* subs; u32 count; Key* keys; u32 nkeys; };

extern "C" void fn_27_22520C(S* arg) {
    for (u32 i = 0; i < arg->count; i++) {
        Sub* e = &arg->subs[i];
        if (e->dst != 0) {
            for (u32 j = 0; j < e->count; j++) {
                u32 key = e->src[j].id;
                e->dst[j] = -1;
                for (u32 k = 0; k < arg->nkeys; k++) {
                    if (key == arg->keys[k].id) {
                        e->dst[j] = k;
                        break;
                    }
                }
            }
        }
    }
}
