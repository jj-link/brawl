#pragma force_active on
extern int fn_8036A24C(int, void *, const void *, int);
extern unsigned long strlen(const char *);

void fn_8036A328(int a, void *b, const char *c) {
    fn_8036A24C(a, b, c, strlen(c));
}