#include <types.h>
#pragma force_active on
struct Color { u8 r, g; s8 b; };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual Color slot17();
};
extern "C" int fn_8015E1E4(Object_vptr_0* obj) {
 Color c = obj->slot17();
 return c.b;
}