#pragma force_active on
void memset(void*, int, unsigned long);

void fn_80392738(void* dest, unsigned long count) {
    memset(dest, 0, count);
}
