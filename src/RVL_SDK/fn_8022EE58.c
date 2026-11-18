#include <types.h>
#pragma force_active on

typedef struct {
    void *p_first;
    void *p_last;
    u16 size;
    u16 total;
    u16 cur_cnt;
    u16 max_cnt;
} FREE_QUEUE_T;

typedef struct {
    u8 pad0[0x2898C];
    FREE_QUEUE_T freeq[9];
    u8 pad1[0x28A7C - 0x28A1C];
    u16 pool_access_mask;
    u8 pool_list[9];
    u8 curr_total_no_of_pools;
} COM_CB;

typedef struct {
    u8 *p_next;
    u8 q_id;
    u8 task_id;
    u8 status;
    u8 type;
} BUF_HDR;

extern u8 lbl_804FD448[0x2ABA];
extern char lbl_8047FAB0[];
extern char lbl_8047FAC8[];
extern void fn_80230570(u16, void *);
extern void fn_8023052C(void);
extern void fn_80230508(void);
extern u8 fn_80230500(void);

void *fn_8022EE58(u32 size)
{
    u8 i;
    COM_CB *p_cb = (COM_CB *)(lbl_804FD448 + 0x54);
    FREE_QUEUE_T *Q;
    BUF_HDR *p_hdr;

    if (size == 0) {
        fn_80230570(0xFFF6, lbl_8047FAB0);
        return 0;
    }

    for (i = 0; i < p_cb->curr_total_no_of_pools; i++) {
        if (size <= p_cb->freeq[p_cb->pool_list[i]].size) {
            break;
        }
    }

    if (i == p_cb->curr_total_no_of_pools) {
        fn_80230570(0xFFF7, lbl_8047FAC8);
        return 0;
    }

    fn_8023052C();

    for (; i < p_cb->curr_total_no_of_pools; i++) {
        if (((u16)1 << p_cb->pool_list[i]) & p_cb->pool_access_mask) {
            continue;
        }
        Q = &p_cb->freeq[p_cb->pool_list[i]];
        if (Q->cur_cnt < Q->total) {
            p_hdr = (BUF_HDR *)Q->p_first;
            Q->p_first = p_hdr->p_next;
            if (!Q->p_first) {
                Q->p_last = 0;
            }
            if (++Q->cur_cnt > Q->max_cnt) {
                Q->max_cnt = Q->cur_cnt;
            }
            fn_80230508();
            p_hdr->task_id = fn_80230500();
            p_hdr->status = 1;
            p_hdr->p_next = 0;
            p_hdr->type = 0;
            return (u8 *)p_hdr + 8;
        }
    }
    fn_80230508();
    return 0;
}
