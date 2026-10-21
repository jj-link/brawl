#pragma force_active on
extern void fn_80368BA0(void* p);

void fn_80367C54(void* p) {
    if (p == 0 || *(int*)p == 0) {
        return;
    }
    fn_80368BA0(p);
}
