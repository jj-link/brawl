#include <types.h>
#pragma force_active on
extern u32 lbl_805A1210;
extern u32 lbl_805A1220;
extern void fn_803C7D64(int, int);
extern int fn_803C2BB8(signed char, int);
extern int fn_803C8014(u32, int);
extern int fn_803C2AB0(void);
typedef struct E {
    u32 *a0;
    int a4;
    int a8;
    int aC;
    int a10;
    signed char a14;
} E;
static inline E *get(u32 n) {
    if (n < lbl_805A1210 && lbl_805A1220 != 0)
        return (E *)(lbl_805A1220 + n * 0x140);
    return 0;
}
static inline u32 getstate(u32 n) {
    E *p = get(n);
    u32 *q;
    if (p == 0 || p->a8 == 0 || (q = p->a0) == 0)
        return 0;
    return q[3];
}
static inline void setstate(u32 n, u32 state) {
    E *p = get(n);
    u32 *q;
    if (p != 0 && p->a8 != 0 && (q = p->a0) != 0 && state <= 1)
        q[3] = state;
}
int fn_803C68E0(u32 arg0) {
    E *e = get(arg0);
    u32 state;
    if (e == 0 || e->a0 == 0) return 0xB003;
    if (e->a8 == 0) return 0xB003;
    if (e != 0 && e->a8 != 0) fn_803C7D64(e->a8, 0);
    state = getstate(arg0);
    setstate(arg0, 1);
    if (fn_803C2BB8(e->a14, 0) == 0) {
        setstate(arg0, 0);
        if (fn_803C8014(arg0, 1) == 0) {
            setstate(arg0, state);
            return 0;
        }
        setstate(arg0, state);
        return 5;
    }
    setstate(arg0, 0);
    fn_803C8014(arg0, 1);
    setstate(arg0, state);
    return fn_803C2AB0();
}