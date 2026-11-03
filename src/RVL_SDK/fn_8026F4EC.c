#pragma force_active on
typedef struct {
    char pad0[0x10];
    unsigned int field10;
    char pad14[0x18];
    unsigned int field2c;
    char pad30[0xc];
    void *field3c;
} State;
extern char lbl_80532150[];
extern void *lbl_8059EE5C;
extern void *lbl_805A0508;
extern void *lbl_805A0E80;
extern unsigned int fn_80204688(unsigned int, unsigned int, unsigned int);
extern void fn_80204E7C(void *, unsigned int, unsigned int);
extern void *fn_80204E5C(void *, int);
extern void *fn_8026F9D0(void *, const State *);
extern void fn_8026FD6C(void *);
static inline int get_state(const State *p) {
    int result;
    if (p->field3c)
        result = 0;
    else {
        result = 2;
        if (p->field10)
            result = 1;
    }
    return result;
}
void fn_8026F4EC(const State *p) {
    void *mem;
    if (get_state(p) == 1) {
        fn_80204E7C(lbl_80532150, fn_80204688(p->field10, p->field2c, 0), 0x20);
        lbl_8059EE5C = lbl_80532150;
    }
    switch (get_state(p)) {
    case 0:
        lbl_805A0508 = p->field3c;
        lbl_8059EE5C = p->field3c;
        break;
    case 1:
        lbl_805A0508 = lbl_8059EE5C;
        break;
    case 2:
        lbl_8059EE5C = lbl_805A0508;
        break;
    }
    mem = fn_80204E5C(lbl_8059EE5C, 0x768);
    if (mem) {
        if (mem)
            mem = fn_8026F9D0(mem, p);
        lbl_805A0E80 = mem;
    }
    fn_8026FD6C(lbl_805A0E80);
}