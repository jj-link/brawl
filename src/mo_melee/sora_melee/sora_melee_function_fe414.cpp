#pragma force_active on
struct Item {
    int a;
    int b;
    int c;
};

struct Holder {
    int a;
    int b;
    int flag;
    Item items[1];
};

extern "C" {
Item* fn_27_FE414(Holder* h, int idx) {
    int n = (h->flag >> 30) + idx;
    if (n >= 1) {
        n -= 1;
    }
    return &h->items[n];
}
}
