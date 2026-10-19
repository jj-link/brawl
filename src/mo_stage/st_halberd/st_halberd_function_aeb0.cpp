#pragma force_active on
struct Entry {
    int pad[2];
    int count;
};

extern "C" void* fn_57_AEB0(Entry* self, int index) {
    int hi = self->count >> 28;
    int sum = hi + index;
    if (sum >= 7) {
        sum -= 7;
    }
    return (char*)self + (sum << 3) + 12;
}
