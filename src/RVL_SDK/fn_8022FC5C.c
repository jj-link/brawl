#include <types.h>
#pragma force_active on
extern u8 lbl_804FD448[];
extern char lbl_8047FBE0[];
extern void fn_8023052C(void);
extern void fn_802305A0(void *);
extern void fn_80230570(u16, char *);
extern void fn_80230508(void);

typedef struct FREE_Q {
    void *p_first;
    void *p_last;
    u16 size;
    u16 total;
    u16 cur_cnt;
    u16 max_cnt;
} FREE_Q;

typedef struct COM {
    u8 pad0[0x2898C];
    FREE_Q freeq[9];
    u8 *pool_start[9];
    u8 *pool_end[9];
    u16 pool_size[9];
    u8 pad1[8];
    u8 pool_list[9];
    u8 curr_total_no_of_pools;
} COM;

static inline void gki_remove_from_pool_list(u8 pool_id)
{
    COM *p_cb = (COM *)(lbl_804FD448 + 0x54);
    u8 i;

    for (i = 0; i < p_cb->curr_total_no_of_pools; i++) {
        if (pool_id == p_cb->pool_list[i])
            break;
    }
    while (i < (p_cb->curr_total_no_of_pools - 1)) {
        p_cb->pool_list[i] = p_cb->pool_list[i + 1];
        i++;
    }
}

void fn_8022FC5C(u8 pool_id)
{
    FREE_Q *Q;
    COM *p_cb = (COM *)(lbl_804FD448 + 0x54);

    if (pool_id >= 9 || !p_cb->pool_start[pool_id]) {
        return;
    }
    fn_8023052C();
    Q = &p_cb->freeq[pool_id];
    if (!Q->cur_cnt) {
        Q->size = 0;
        Q->total = 0;
        Q->cur_cnt = 0;
        Q->max_cnt = 0;
        Q->p_first = 0;
        Q->p_last = 0;
        fn_802305A0(p_cb->pool_start[pool_id]);
        p_cb->pool_start[pool_id] = 0;
        p_cb->pool_end[pool_id] = 0;
        p_cb->pool_size[pool_id] = 0;
        gki_remove_from_pool_list(pool_id);
        p_cb->curr_total_no_of_pools--;
    } else {
        fn_80230570(0xFFF8, lbl_8047FBE0);
    }
    fn_80230508();
}
