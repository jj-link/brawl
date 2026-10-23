#pragma force_active on
extern void fn_80202710(void *arg0);

void fn_80202614(void *arg0) {
    *(float *)((char *)arg0 + 0x114) = *(float *)((char *)arg0 + 0x158);
    fn_80202710(arg0);
}
