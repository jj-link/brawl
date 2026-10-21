#pragma force_active on
extern "C" {
void fn_8006271C(void *arg0) {
    if (*(unsigned int *)((char *)arg0 + 0x24) == 2u) {
        *(int *)((char *)arg0 + 0x24) = 3;
    }
}
}
