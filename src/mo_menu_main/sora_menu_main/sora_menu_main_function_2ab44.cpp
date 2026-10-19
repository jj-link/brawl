#pragma force_active on
struct Item {
    int pad;
    int value;
};

extern "C" int fn_2_2AB44(const Item *a, const Item *b) {
    return b->value - a->value;
}
