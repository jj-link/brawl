#pragma force_active on
typedef unsigned char u8;
struct S { char pad[0xb7]; u8 f; };
int fn_8027A0A4(struct S *p) {
    return p->f & 1;
}
