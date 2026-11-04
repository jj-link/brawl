#pragma force_active on
class SearchSource {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* getAt(int index);
};

typedef int (*CompareFn)(void*, void*);

extern "C" int fn_27_22AA8(void* ctx, SearchSource* src, CompareFn cmp, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    int c = cmp(ctx, src->getAt(mid));
    if (c == 0) {
        return mid;
    }
    if (lo == hi) {
        return -(lo + 1);
    }
    if (c > 0) {
        return fn_27_22AA8(ctx, src, cmp, mid + 1, hi);
    }
    return fn_27_22AA8(ctx, src, cmp, lo, mid);
}
