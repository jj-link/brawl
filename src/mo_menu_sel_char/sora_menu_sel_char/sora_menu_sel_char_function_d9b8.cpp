#pragma force_active on
extern "C" int exchangeMuSelchkindToMuCharKind__6muMenuFiii(int);
extern "C" int isCharRefered__6muMenuFiii(int);
extern "C" void setCharRefered__6muMenuFiii(int);
extern "C" int fn_10_DA54(void*, int);

class MenuTarget {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void invoke(void*);
};

struct MenuEntry {
    unsigned char padding[0x10];
    void* resource;
};

struct CharacterMenu {
    unsigned char padding[0x13C];
    MenuEntry* entries[189];
    MenuTarget* target;
};

extern "C" void fn_10_D9B8(CharacterMenu* self, int kind) {
    int referred = isCharRefered__6muMenuFiii(
        exchangeMuSelchkindToMuCharKind__6muMenuFiii(kind));
    int state = 1;
    if (referred != 0) {
        state = 2;
    }

    if (state != 2) {
        setCharRefered__6muMenuFiii(
            exchangeMuSelchkindToMuCharKind__6muMenuFiii(kind));

        int index = fn_10_DA54(self, kind);
        self->target->invoke(self->entries[index + 0x70]->resource);
    }
}
