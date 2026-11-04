#include <types.h>
#pragma force_active on

extern "C" {

extern char lbl_80413E38[];

struct Holder {
    char pad0[0x1C];
    void* field1C;
    char pad20[0x20];
    void* field40;
    u32 field44;
    u32 field48;
    void* field4C;
    u32 field50;
    u32 field54;
};

class Visitor {
public:
    virtual void f0();
    virtual void f1();
    virtual void array(const char* name, int size, void* data, u32 count, u32 flags);
    virtual void object(const char* name, int id, void* data);
};

void fn_802F0570(Holder* self, Visitor* visitor) {
    visitor->object(lbl_80413E38, 1, self->field1C);

    const char* name1 = lbl_80413E38 + 6;
    if (!(self->field48 & 0x80000000)) {
        visitor->array(name1, 8, self->field40,
                       self->field44 * 8, self->field48 * 8);
    }

    const char* name2 = lbl_80413E38 + 0x11;
    if (!(self->field54 & 0x80000000)) {
        visitor->array(name2, 4, self->field4C,
                       self->field50 * 0x10, self->field54 * 0x10);
    }
}

}
