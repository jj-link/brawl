#include <mu/menu.h>
#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#pragma force_active on
extern "C" int exchangeMuCharKindToMuStockchkind__6muMenuFiii(int);
extern "C" int fn_8004D9E8(void*);
extern "C" const char* fn_800AFA8C(int);
extern "C" int fn_2_25B34(int, int);
extern "C" void fn_2_29DC8(void*, int);
extern "C" void* g_GameGlobal;
extern "C" int lbl_2_data_3410[];
struct Base { char pad[0x668]; };
struct State : Base {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void update(int, int, int);
    virtual void select(int);
    unsigned long index;
    char pad670[8];
    MuMsg* msg;
    char pad67c[8];
    MuObject* node;
    MuObject* tex;
    char pad68c[8];
    int selected;
    int first;
    int cursor;
    char pad6a0[4];
    int* characters;
};
extern "C" void fn_2_29B44(State* self, int arg) {
    int character = self->characters[self->selected];
    self->tex->setFrameTex((float)(muMenu::exchangeGmCharacterKind2Something(exchangeMuCharKindToMuStockchkind__6muMenuFiii(character)) * 10 + 1));
    if (fn_8004D9E8(g_GameGlobal)) {
        self->msg->printf(self->index, fn_800AFA8C(exchangeMuCharKindToMuStockchkind__6muMenuFiii(character)));
    }
    self->msg->printf(self->index + 1, muMenu::exchangeMuStockchkind2MuCharName(exchangeMuCharKindToMuStockchkind__6muMenuFiii(character)));
    int j = 0;
    int i = self->first;
    for (; j < 7 && i < 24; ++j, ++i) {
        self->update(lbl_2_data_3410[i], fn_2_25B34(lbl_2_data_3410[i], character), j);
    }
    self->node->setFrameNode((float)self->cursor);
    fn_2_29DC8(self, arg);
    self->select(lbl_2_data_3410[self->first + self->cursor]);
}