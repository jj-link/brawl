#include <types.h>
#pragma force_active on
typedef struct Obj {
    char pad0[0x24];
    int state;
    int prev;
    u8 selected;
    char pad2d[0x64-0x2d];
    int id;
    char pad68[0x88-0x68];
    void (*callback)(int,int,int,int,int,void *);
    void *context;
    char pad90[0x36d-0x90];
    u8 count;
    char pad36e[0x468-0x36e];
    int ids[(0x514-0x468)/4];
    int flag;
    char pad518[0x648-0x518];
    u8 entries[0x20];
    int bits;
} Obj;
extern Obj *lbl_805A0F88;
extern void fn_80341454(void);
extern void fn_80342168(void);
static inline int make_bits(u8 *tab, int n) {
    int bits = 0;
    int i;
    for (i = 0; i < n; i++) {
        bits |= 1 << tab[i];
    }
    return bits;
}
void fn_8033B208(int a, int b, int c, int d, int e) {
    int i;
    int bits;
    if (a == 0 && b != 0) {
        if (lbl_805A0F88->flag == 0) {
            fn_80341454();
            lbl_805A0F88->prev = lbl_805A0F88->state;
            lbl_805A0F88->state = 3;
        }
    } else if (a == 0) {
        lbl_805A0F88->prev = lbl_805A0F88->state;
        lbl_805A0F88->state = 6;
        for (i = 0; i <= lbl_805A0F88->count; i++) {
            if (lbl_805A0F88->id == lbl_805A0F88->ids[i]) {
                lbl_805A0F88->selected = lbl_805A0F88->entries[i];
                break;
            }
        }
    }
    bits = make_bits(lbl_805A0F88->entries, lbl_805A0F88->count + 1);
    lbl_805A0F88->bits = bits;
    fn_80342168();
    lbl_805A0F88->callback(a,b,c,d,e,lbl_805A0F88->context);
    if (a != 0 && lbl_805A0F88 != 0 && lbl_805A0F88->state == 5) {
        lbl_805A0F88->prev = lbl_805A0F88->state;
        lbl_805A0F88->state = 3;
    }
}