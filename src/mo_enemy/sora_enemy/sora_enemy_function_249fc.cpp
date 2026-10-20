#pragma force_active on
struct Pair {
    unsigned int data[2];
};

struct Result {
    Pair first;
    Pair second;
};

extern "C" void fn_41_249FC(Result* dst, const Pair* first, const Pair* second) {
    dst->first = *first;
    dst->second = *second;
}
