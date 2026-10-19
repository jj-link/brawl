#pragma force_active on
extern "C" void *fn_27_2637E8(void *obj, int a, int b, int c);

struct AdvStageList {
    char pad[0x14c];
    void *obj;
    unsigned int count;
    unsigned int *list;
};

extern "C" void fn_40_1CDF0(AdvStageList *self, unsigned int key) {
    unsigned int i;
    unsigned int count = self->count;
    for (i = 0; i < count; i++) {
        unsigned int v = self->list[i];
        if (v == key) {
            fn_27_2637E8(self->obj, 0, 0, i);
            return;
        }
    }
}
