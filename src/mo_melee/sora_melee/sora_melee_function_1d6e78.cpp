#pragma force_active on
struct Count { int value; operator int() const { return value; } void operator++(int) { value++; } };
struct Entry { char pad[8]; Count count; };
struct Class_270C0_base { char* data; char pad[8]; };
class Class_270C0 : public Class_270C0_base {
public:
 virtual void fn_27_11110C();
 virtual void fn_27_112FEC();
 virtual void fn_27_1113B8();
 virtual void fn_27_111850();
 virtual void fn_27_111894();
 virtual void fn_27_1118A0();
 virtual void fn_27_1118E4();
 virtual void fn_27_111A14();
 virtual void fn_27_110FC8();
 virtual void fn_27_111AB8();
 virtual void fn_27_112E78();
 virtual void fn_27_112E94();
 virtual void fn_27_112EB0();
 virtual void fn_27_112ECC(int, int, int);
 virtual void fn_27_112EE8();
 virtual void fn_27_112F04();
 virtual void fn_27_112F20();
 virtual void fn_27_112F3C();
 virtual void fn_27_112F98();
 virtual void fn_27_112FB4(Entry*);
};
extern "C" Entry* fn_27_1D72F4(void*, int);
extern "C" int fn_27_1D53E4(void*, unsigned int, unsigned int);

extern "C" void fn_27_1D6E78(Class_270C0* self) {
 if (*(int*)(self->data + 0xc3c) == 2) {
  Entry* entry = fn_27_1D72F4(self->data + 0xc44, 0);
  if (entry) {
   if (entry->count > 0) {
    entry->count++;
    return;
   }
   self->fn_27_112FB4(entry);
   entry->count++;
   int value = fn_27_1D53E4(self->data + 0x9e8, 12, 0);
   if (fn_27_1D53E4(self->data + 0x9e8, 13, 0) < value)
    self->fn_27_112ECC(1, 13, 0);
  }
 }
}
