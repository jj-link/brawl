#pragma force_active on
typedef unsigned char u8;
struct S { char pad[0x1f]; u8 f; };
int fn_801F2D54(struct S *p) {
    return p->f & 1;
}
