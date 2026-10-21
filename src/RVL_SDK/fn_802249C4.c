#pragma force_active on
typedef void (*EntryFn)(unsigned int, void *);

typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    EntryFn fn;
} Entry;

extern Entry lbl_804F9F70[];

void fn_802249C4(unsigned int idx, void *arg)
{
    EntryFn f;

    lbl_804F9F70[idx].a = 0;
    f = lbl_804F9F70[idx].fn;
    lbl_804F9F70[idx].fn = 0;
    if (f) {
        f(idx, arg);
    }
}
