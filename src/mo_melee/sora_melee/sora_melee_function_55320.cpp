#pragma force_active on
struct Item { int pad0; int key; };
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual Item* slot2(int);
};
struct Compare {
 int operator()(Item* a, Item* b) const {
  if (a->key == b->key) return 0;
  return a->key < b->key ? -1 : 1;
 }
};
extern "C" int fn_27_55320(Item* item, Object_vptr_0* source, Compare cmp, int lo, int hi) {
 int mid = lo + (hi-lo)/2;
 int c = cmp(item, source->slot2(mid));
 if (c == 0) return mid;
 if (lo == hi) return -(lo+1);
 if (c > 0) return fn_27_55320(item,source,cmp,mid+1,hi);
 return fn_27_55320(item,source,cmp,lo,mid);
}
