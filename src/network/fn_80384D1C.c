#pragma force_active on
typedef struct Entry { int kind, a, b, c, d, e; void (*callback)(); } Entry;
extern void *lbl_805A10C4;
extern int fn_8035A590(void *);
extern Entry *fn_8035A598(void *, int);
extern void fn_8035A918(void *, int);
void fn_80384D1C(int index, int arg1, long long arg2, int arg4, int arg5)
{
    Entry *entry;
    void (*callback)();
    if (index < 0 || index >= fn_8035A590(lbl_805A10C4)) return;
    entry = fn_8035A598(lbl_805A10C4, index);
    callback = entry->callback;
    if (callback != 0) {
        switch (entry->kind) {
        case 0: callback(entry->a, entry->b, arg1, arg4, entry->e); break;
        case 1: callback(entry->a, entry->b, entry->c, entry->d, arg1, entry, arg2, arg4, arg5, entry->e); break;
        case 2: callback(entry->a, entry->b, entry->c, entry->d, arg1, entry, arg2, entry->e); break;
        case 3: callback(entry->a, entry->b, arg1, entry->e); break;
        }
    }
    fn_8035A918(lbl_805A10C4, index);
}