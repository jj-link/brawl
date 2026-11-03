#pragma force_active on
struct Entry { int unused; int id; };
class Class_CF8 {
public:
 virtual void fn_27_1000C();
 virtual void fn_27_100D0();
 virtual Entry& fn_27_100CC(int);
 virtual void fn_27_10094();
 virtual void fn_27_100C8();
};
class soNullable {
public:
 virtual void isNull();
 virtual void fn_27_1E6058();
 virtual void fn_27_1E6158();
 virtual void fn_27_1E64B4();
 virtual int fn_27_1E61AC();
 char padding[12];
 Class_CF8 array;
 int find(int id) {
  if (id <= -1) return -1;
  int count = fn_27_1E61AC();
  for (int i = 0; i < count; ++i) {
   if (id == array.fn_27_100CC(i).id) return i;
  }
  return -1;
 }
};
extern "C" int fn_27_1E61BC(soNullable* self, int id) {
 return self->find(id) >= 0;
}