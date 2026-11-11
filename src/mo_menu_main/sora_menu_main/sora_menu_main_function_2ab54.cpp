#pragma force_active on
#include <types.h>
#include <mu/mu_msg.h>
#include <mu/menu.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>

extern "C" {
s32 fn_2_25B90(s32 idx);
s32 fn_2_25BA8(s32 idx);
s32 fn_2_25BD8(char* buf, s32* out, s32 c, s32 d, s32 e);
void fn_800B92D8(void* msg, u32 index, char* buf, u32 len);
s32 exchangeMuCharKindToMuStockchkind__6muMenuFiii(s32 kind);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern char lbl_2_data_3358[];
}

struct Obj {
    char pad0[0x66C];
    s32 unk66C;
    char pad1[0x8];
    MuMsg* msg;
    char pad2[0x10];
    void* unk68C;
    char pad3[0x24];
    MuObject* unk6B4;
    MuObject* unk6B8;
    MuObject* unk6BC;
};

extern "C" void fn_2_2AB54(Obj* self, s32 kind, s32 arg2, s32 arg3) {
    char* base = lbl_2_data_3358;
    s32 sp8;
    MuObject* object;
    char* str;
    char buf[0x80];
    s32 var;

    if (kind < 0x18) {
        self->msg->printIndex(arg3 + self->unk66C + 4, fn_2_25BA8(kind));
        switch (fn_2_25B90(kind)) {
        case 2:
            var = 0x5F5E0FF;
            break;
        case 6:
            var = 0x5B8D7F;
            break;
        default:
            var = 0x5F5E0FF;
            break;
        }
        fn_800B92D8(self->msg, arg3 + self->unk66C + 0xB, buf,
                    fn_2_25BD8(buf, &sp8, kind, arg2, var) + 1);
        if (sp8 != -1) {
            self->msg->printIndex(arg3 + self->unk66C + 0x12, (u32)sp8);
        } else {
            self->msg->printf(arg3 + self->unk66C + 0x12, base + 0x184);
        }
    } else {
        self->msg->printIndex(arg3 + self->unk66C + 4, fn_2_25BA8(kind));
        if (arg2 == 0x23) {
            str = base + 0x188;
        } else {
            str = base + 0x184;
            switch (kind) {
            case 0x18:
                object = self->unk6B4;
                break;
            case 0x19:
                object = self->unk6B8;
                break;
            case 0x1A:
                object = self->unk6BC;
                break;
            }
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                self->unk68C, object->m_sceneModel, base + 0x18C);
            object->setFrameTex(
                (float)(muMenu::exchangeGmCharacterKind2Something(
                            exchangeMuCharKindToMuStockchkind__6muMenuFiii(arg2)) *
                            0xA +
                        1));
            object->setFrameNode((float)arg3);
        }
        self->msg->printf(arg3 + self->unk66C + 0xB, str);
        self->msg->printf(arg3 + self->unk66C + 0x12, base + 0x184);
    }
}
