#pragma force_active on
struct Entry { unsigned short a, b; };
struct Arr { Entry* base; int count; };
inline Entry* shift(Entry* first, Entry* last) {
    while (first < last) {
        *first = *(first + 1);
        ++first;
    }
    return first;
}
extern "C" void fn_8030AE04(Arr* self, int a, int b) {
    Entry* first = self->base + a;
    Entry* last = self->base + b - 1;
    while (first < last) {
        *first = *(first + 1);
        ++first;
    }
    self->count -= 2;
    last = self->base + self->count;
    for (; first < last; ) {
        *first = *(first + 2);
        ++first;
    }
}
