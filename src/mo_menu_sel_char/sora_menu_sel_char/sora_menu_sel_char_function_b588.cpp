#include <mu/selchar/mu_selchar.h>
#pragma force_active on

extern "C" {
int fn_10_B678(muSelCharTask*, int);
void fn_10_FD00(muSelCharTask*, int);
int fn_10_B398(muSelCharTask*, int, int, int, int);
void fn_10_10384(muSelCharTask*, int);
}

extern "C" int fn_10_B588(muSelCharTask* self) {
    int mode = 1;
    int i = 0;
    int complete = 0;
    do {
        if (fn_10_B678(self, i) == 0)
            break;
        ++i;
    } while (i < 35);
    if (i >= 35)
        complete = 1;
    if (complete != 0)
        mode = 2;
    fn_10_FD00(self, mode);
    if (complete != 0) {
        int total = 0;
        int index = 0;
        do {
            total += fn_10_B398(self, index, *(int*)((char*)self + 0x5E0), 0, 0);
            ++index;
        } while (index < 35);
        self->dispHighScore(3, total, 1);
    } else {
        fn_10_10384(self, 3);
    }
    return complete;
}
