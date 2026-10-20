#pragma force_active on
extern "C" {
extern void* g_GameGlobal;

void fn_8006BCA8(char*);
int fn_8004D808(void*, char*);
int fn_8004D148(void*);
void fn_8004D334(void*, int, const void*, int);
void fn_8004D97C(void*, int, const void*);
void fn_8004DA60(void*, unsigned char, const void*);
void fn_16_301C(void*, short);
void fn_16_347C(void*);

int fn_16_4C90(void* self, const void* name, const void* arg3,
               const void* arg4, int allowExisting) {
    char buf[16];
    fn_8006BCA8(buf);

    void* global = g_GameGlobal;
    int found = fn_8004D808(global, buf);

    if (allowExisting == 0 && found >= 0)
        return -1;

    int index = found;
    if (found < 0)
        index = fn_8004D148(global);

    if (index >= 120)
        return -2;

    if (found < 0)
        fn_8004D334(global, index, name, 0);

    fn_8004D97C(global, index, arg3);
    fn_8004DA60(global, (unsigned char)index, arg4);

    if (found < 0)
        fn_16_301C(self, (short)index);

    fn_16_347C(self);
    return index;
}
}
