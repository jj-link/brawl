#include <types.h>
#pragma force_active on

extern char lbl_804129D0[];

struct Entity {
    char pad0[0x68];
    void* f68;
    char pad6C[0x1A0 - 0x6C];
    void* f1A0;
    char pad1A4[0x1B4 - 0x1A4];
    void* f1B4;
    u32 f1B8;
    u32 f1BC;
    void* f1C0;
    u32 f1C4;
    u32 f1C8;
    void* f1CC;
    u32 f1D0;
    u32 f1D4;
};

class Visitor {
public:
    virtual void slot0();
    virtual void slot1(const char* name, int id, void* data);
    virtual void slot2(const char* name, int size, void* value, u32 length, u32 count);
    virtual void slot3(const char* name, int size, void* value);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
};

extern "C" {

void fn_802F0570(Entity* self, Visitor* visitor);

void fn_802E13DC(Entity* arg0, Visitor* arg1) {
    arg1->slot1(lbl_804129D0, 2, arg0);
    fn_802F0570(arg0, arg1);
    arg1->slot3(lbl_804129D0 + 7, 4, arg0->f1A0);
    arg1->slot3(lbl_804129D0 + 0x13, 4, arg0->f68);

    u32 flags1 = arg0->f1BC;
    const char* name1 = lbl_804129D0 + 0x1F;
    if (!(flags1 & 0x80000000)) {
        arg1->slot2(name1, 4, arg0->f1B4, arg0->f1B8 * 4, flags1 * 4);
    }

    u32 flags2 = arg0->f1C8;
    const char* name2 = lbl_804129D0 + 0x2F;
    if (!(flags2 & 0x80000000)) {
        arg1->slot2(name2, 4, arg0->f1C0, arg0->f1C4 * 4, flags2 * 4);
    }

    u32 flags3 = arg0->f1D4;
    const char* name3 = lbl_804129D0 + 0x3C;
    if (!(flags3 & 0x80000000)) {
        arg1->slot2(name3, 4, arg0->f1CC, arg0->f1D0 * 4, flags3 * 4);
    }

    arg1->slot6();
}

}
