#pragma force_active on
#ifdef __cplusplus
extern "C" {
#endif

extern void fn_8037E8B4(void);
extern void fn_8037C790(void (*callback)(void));

void fn_8037EEDC(void) {
    fn_8037C790(fn_8037E8B4);
}

#ifdef __cplusplus
}
#endif
