#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3(void*, int);
 virtual void slot4();
 virtual void slot5();
 virtual void slot6(void*);
 virtual void slot7(void*);
};
struct Inner { char pad[0x18]; Object_vptr_0* object; };
struct Middle { char pad[0xd8]; Inner* inner; };
struct Owner { char pad[0x60]; Middle* middle; };
extern "C" void* fn_98_14878(void*);
extern "C" void fn_98_141E8(void* owner, void* a, void* b) {
 Object_vptr_0* object = ((Owner*)owner)->middle->inner->object;
 object->slot3(a, 1);
 object->slot6(a);
 object->slot7(b);
 void* next = fn_98_14878(owner);
 if (next) fn_98_141E8(next, a, b);
}
