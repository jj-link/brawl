#pragma force_active on
struct Entry {
    int first;
    int second;
};

extern "C" Entry* fn_70_9304(int* object, int index) {
    int packed = object[2];
    int adjustment = packed >> 28;
    int result = adjustment + index;
    if (result >= 6) {
        result -= 6;
    }
    return (Entry*)((char*)object + result * sizeof(Entry) + 12);
}
