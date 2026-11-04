#pragma force_active on
extern "C" int fn_80300488(void* a, void* b) {
    int va = *(int*)((char*)a + 0x28);
    int vb = *(int*)((char*)b + 0x28);
    void* arr;
    void* winner;
    void* loser;
    int count;
    int i;

    if (va <= vb) {
        winner = a;
        loser = b;
    } else {
        winner = b;
        loser = a;
    }

    count = *(int*)((char*)winner + 0x28);
    for (i = 0; i < count; i++) {
        arr = *(void**)((char*)winner + 0x24);
        if (*(void**)((char*)arr + i * 8 + 4) == loser) {
            return *(int*)((char*)arr + i * 8);
        }
    }
    return 0;
}