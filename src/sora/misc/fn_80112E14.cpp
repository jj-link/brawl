#pragma force_active on
struct Entry {
    void *owner;
    int value;
    unsigned char flag;
    char pad[3];
};

extern "C" void fn_80112E14(char *self, unsigned char *src, int *val) {
    unsigned char f = src[0x55];
    Entry *p = (Entry *)(self + 0x68);
    for (int i = 8; i > 0; i--) {
        if (p->owner == 0) {
            p->owner = src;
            p->value = *val;
            p->flag = f;
            return;
        }
        p++;
    }
}
