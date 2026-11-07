#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual int slot4(unsigned int);
 virtual void slot5(int, unsigned int);
};
struct Inner { char pad[0x64]; Object_vptr_0* work; };
struct Middle { char pad[0xd8]; Inner* inner; };
struct Self { char pad[0x60]; Middle* middle; };
struct Param { char pad[0xc]; int value; char pad2[0x13]; unsigned char a; unsigned char b; };
extern "C" void fn_27_135EDC(void*);
extern "C" void fn_104_9B3C(Self* self, Param* param) {
 fn_27_135EDC(self);
 Object_vptr_0* work = self->middle->inner->work;
 int count = work->slot4(0x20000000);
 if (count < 8) {
  work->slot5(param->value, count + 0x20000001);
  work->slot5(param->a, count + 0x20000009);
  work->slot5(param->b, count + 0x20000011);
  count++;
 }
 work->slot5(count, 0x20000000);
}