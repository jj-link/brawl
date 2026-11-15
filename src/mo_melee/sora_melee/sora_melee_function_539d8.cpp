#pragma force_active on
#pragma inline_depth(4)

struct SNode27 {
    int pad;
    int key;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual SNode27* slot1(int index);
};

struct SSrc27 {
    int pad0;
    int pad1;
    Object_vptr_0* obj;
};

extern "C" int fn_27_539D8(void* src, int target, int lo, int hi) {
    int key;
    int mid;

    mid = lo + (hi - lo) / 2;
    key = ((SSrc27*)src)->obj->slot1(mid)->key;

    if (key == target) {
        return mid;
    }
    if (lo == hi) {
        return -1;
    }
    if (key < target) {
        return fn_27_539D8(src, target, mid + 1, hi);
    }
    if (key > target) {
        return fn_27_539D8(src, target, lo, mid);
    }
    return -1;
}
