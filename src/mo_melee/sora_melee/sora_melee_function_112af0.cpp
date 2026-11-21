#pragma force_active on
extern "C" int randi__Fl(long);

extern "C" int fn_27_112AF0(void **arg0) {
    int buf[64];
    int *out;
    int off;
    char *item;
    int count;
    int i;
    int n;

    count = 0;
    out = buf;
    off = 0;
    n = *(int *)((char *)*arg0 + 0x7F8);
    for (i = 0; i < n; i++) {
        item = (char *)*arg0 + off;
        int t = *(int *)(item + 0x4F8);
        if (t >= 0x46 && t <= 0x59) {
            float f = *(float *)(item + 0x4FC);
            count++;
            *out++ = (int)f;
            if (count >= 0x40) {
                break;
            }
        }
        off += 12;
    }
    if (count > 0) {
        return buf[randi__Fl(count)];
    }
    return -1;
}
