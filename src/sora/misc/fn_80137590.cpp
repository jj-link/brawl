#pragma force_active on
extern "C" unsigned int fn_80134344(void* p, unsigned int idx);

extern "C" int fn_80137590(void* p) {
    int count = 0;

    if (fn_80134344(p, 0) == 1U) {
        count = 1;
    }
    if (fn_80134344(p, 1) == 1U) {
        count += 1;
    }
    if (fn_80134344(p, 2) == 1U) {
        count += 1;
    }
    if (fn_80134344(p, 3) == 1U) {
        count += 1;
    }
    if (fn_80134344(p, 4) == 1U) {
        count += 1;
    }
    if (fn_80134344(p, 6) == 1U) {
        count += 1;
    }
    if (fn_80134344(p, 5) == 1U) {
        count += 1;
    }
    if (fn_80134344(p, 7) == 1U) {
        count += 1;
    }

    return count;
}
