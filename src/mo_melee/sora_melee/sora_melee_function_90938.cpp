#pragma force_active on
#pragma inline_depth(4)
struct Item { int field0; int key; };
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Item* slot1(int);
};
extern "C" int fn_27_90938(void* ctx, int target, int low, int high) {
    int mid = low + (high - low) / 2;
    int key = (*(Object_vptr_0**)((char*)ctx + 0x10))->slot1(mid)->key;
    if (key == target) return -1;
    if (key < target) {
        if (low == high) return mid + 1;
        return fn_27_90938(ctx, target, mid + 1, high);
    }
    if (key > target) {
        if (low == high) return mid;
        return fn_27_90938(ctx, target, low, mid);
    }
    return -1;
}