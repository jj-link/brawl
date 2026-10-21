#pragma force_active on
extern void fn_8035B264(void *, void *, int);
extern void fn_80378018(void *);
extern void fn_80374BC8(void);

void fn_80374880(void *arg0) {
    fn_8035B264(*(void **)((char *)arg0 + 0xC), fn_80374BC8, 0);
    fn_80378018(arg0);
}
