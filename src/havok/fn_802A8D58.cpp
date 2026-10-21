#pragma force_active on
extern "C" {
extern void fn_802A6508(void *, int, int);

void fn_802A8D58(void *a, int b, int c) {
    fn_802A6508(a, c, b);
}
}
