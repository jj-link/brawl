#pragma force_active on
#pragma inline_depth(4)
struct Element { int field0; int key; };
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Element* slot1(int);
};
extern "C" int fn_27_8FA24(void* ctx, int target, int low, int high) {
    int key;
    int mid = low + (high - low) / 2;
    key = (*(Object_vptr_0**)((char*)ctx + 8))->slot1(mid)->key;
    if (key == target) return mid;
    if (low == high) return -1;
    if (key < target) return fn_27_8FA24(ctx, target, mid + 1, high);
    if (key > target) return fn_27_8FA24(ctx, target, low, mid);
    return -1;
}
