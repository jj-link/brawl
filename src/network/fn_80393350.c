#pragma force_active on
typedef struct Work {
    unsigned char pad[0x24];
    void *data;
    int count;
} Work;

extern Work *fn_803970CC(int);
extern int fn_8039718C(int, Work *, int, int);
extern int fn_80392880(void *);

int fn_80393350(int arg0, int *arg1, int arg2, int *arg3, int arg4)
{
    int total = 0;
    Work *work = fn_803970CC(arg0);

    if (work == 0) {
        return 0;
    }
    work->data = 0;

    for (;;) {
        int count;
        void *data;

        if (*arg1 != 0) {
            return 0;
        }
        work->count = 0;
        if (fn_8039718C(arg0, work, arg2, total) < 0) {
            return 0;
        }
        count = work->count;
        data = work->data;
        if (count == 0) {
            break;
        }
        if (data == 0) {
            return 0;
        }
        total += count;

        switch (arg4) {
        case 0:
        case 1:
            *arg3 += count;
            break;
        case 2:
            *arg3 += fn_80392880(data);
            break;
        }
    }
    return 1;
}
