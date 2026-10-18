#pragma force_active on
typedef struct WarioWork {
    char pad[0xc];
    int *counts;
} WarioWork;

extern "C" int fn_110_9960(WarioWork *work, int index) {
    return work->counts[index]++;
}
