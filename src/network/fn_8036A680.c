#pragma force_active on
extern int fn_8036A594(int, void *, const char *, int);
extern unsigned long strlen(const char *);

void fn_8036A680(int a, void *b, const char *c) {
    fn_8036A594(a, b, c, strlen(c));
}
