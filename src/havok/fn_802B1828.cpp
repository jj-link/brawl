#pragma force_active on
extern "C" void fn_802AFF44(void *, int, int);

extern "C" void fn_802B1828(void *arg0, int arg1, int arg2) {
    fn_802AFF44(arg0, arg2, arg1);
}
