#pragma force_active on
#define JOIN(a, b) a##b
#define ASM JOIN(a, sm)

ASM void fn_801ECFE4() {
    nofralloc
    psq_l  f2, 0(r3), 0, 0
    psq_l  f4, 0(r4), 0, 0
    ps_add f6, f2, f4
    psq_st f6, 0(r5), 0, 0
    psq_l  f3, 8(r3), 1, 0
    psq_l  f5, 8(r4), 1, 0
    ps_add f7, f3, f5
    psq_st f7, 8(r5), 1, 0
    blr
}
