#pragma force_active on
extern void fn_80389E18(void* obj, int x, void* p);
extern char* strcpy(char* d, const char* s);

typedef struct {
    char s[256];
    int v;
} T;

void fn_80389944(char* arg0, int arg1, const char* arg2, int arg3) {
    T l;
    T c;
    l.v = arg3;
    strcpy(l.s, arg2);
    c = l;
    fn_80389E18(arg0 + 0x4C, arg1, c.s);
}
