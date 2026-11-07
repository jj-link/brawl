#pragma force_active on
#include <types.h>
extern "C" { extern const float lbl_57_rodata_188; }
class Class_2110 {
public:
    virtual void fn_57_C674();
    virtual void fn_57_BA94();
    virtual void fn_57_BAA4();
    virtual void fn_57_ADD8();
    virtual void fn_57_AB4C();
    virtual void fn_57_A6E0();
    virtual float fn_57_BDD0();
};
struct Entry { unsigned char pad[0xc]; Class_2110* obj; };
struct Owner { unsigned char pad[0x48]; Entry** table; };
extern "C" float fn_57_55E0(Owner* self, int idx) {
    Entry* e = self->table[idx];
    if (e == 0) {
        return lbl_57_rodata_188;
    }
    return e->obj->fn_57_BDD0();
}
