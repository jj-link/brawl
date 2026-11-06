#include <gf/gf_model.h>
#include <gm/gm_global.h>
#pragma force_active on

struct AnimInfoA { char pad[0x10]; unsigned value; };
struct AnimInfoB { char pad[0xc]; unsigned value; };
struct Object { char pad[0x14]; gfModelAnimation* anim; AnimInfoA* a; AnimInfoB* b; };
struct Objects { char pad[0x158]; Object* items[2]; };
struct MenuBase {
    char pad[0x42]; unsigned short selection;
    char pad44[0x634-0x44]; int result;
    char pad638[0x64c-0x638]; Objects* objects;
    char pad650[0x14]; int mode;
};
struct Menu : MenuBase {
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual int slot6(unsigned);
    unsigned short count;
};
extern "C" {
extern const float lbl_2_rodata_610[];
extern char lbl_2_data_20D0[];
unsigned fn_18_12E0(Menu*);
void fn_800B330C(Object*, void*, int);
void fn_800557A8();
}
extern "C" int fn_2_175D4(Menu* self) {
    const float* ro = lbl_2_rodata_610;
    unsigned flags;
    switch (self->mode) {
    case 0:
    case 1: {
        if (ro[4] == ((Object**)self->objects)[self->selection + 0x56]->anim->m_anmObjMatClrRes->GetFrame()) {
            fn_800B330C(((Object**)self->objects)[self->selection + 0x56], lbl_2_data_20D0 + 0x3c, 1);
            self->mode = 2;
        }
        flags = fn_18_12E0(self);
        if (self->slot6(flags)) {
            self->mode = 2;
            return 4;
        }
        if (flags & 0x10) {
            if (self->selection == 1) {
                for (int i = 0; i < 2; ++i) {
                    if (i == self->selection)
                        fn_800B330C(self->objects->items[i], lbl_2_data_20D0 + 0x50, 1);
                    else
                        fn_800B330C(self->objects->items[i], lbl_2_data_20D0 + 0x64, 1);
                }
                self->mode = 3;
                self->result = 15;
                if (self->mode == 2) {
                    unsigned short count = self->count;
                    if ((signed char)count != ((signed char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x18]) {
                        ((signed char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x18] = count;
                        fn_800557A8();
                    }
                }
                return 2;
            }
        } else if (flags & 0x20) {
            for (int i = 0; i < 2; ++i)
                fn_800B330C(self->objects->items[i], lbl_2_data_20D0 + 0x64, 1);
            self->result = 5;
            self->mode = 3;
            if (self->mode == 2) {
                    unsigned short count = self->count;
                    if ((signed char)count != ((signed char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x18]) {
                        ((signed char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x18] = count;
                        fn_800557A8();
                    }
                }
            return 1;
        }
        break;
    }
    case 2: {
        Object* obj = ((Object**)self->objects)[self->selection + 0x56];
        unsigned type;
        if (obj->a) type = obj->a->value;
        else if (obj->b) type = obj->b->value;
        else type = -1;
        if (type == 4 && obj->anim->m_anmObjMatClrRes->GetFrame() >= ro[5])
            fn_800B330C(((Object**)self->objects)[self->selection + 0x56], lbl_2_data_20D0 + 0x28, 1);
        flags = fn_18_12E0(self);
        self->slot6(flags);
        if (flags & 0x10) {
            if (self->selection == 1) {
                for (int i = 0; i < 2; ++i) {
                    if (i == self->selection)
                        fn_800B330C(self->objects->items[i], lbl_2_data_20D0 + 0x50, 1);
                    else
                        fn_800B330C(self->objects->items[i], lbl_2_data_20D0 + 0x64, 1);
                }
                flags = self->count;
                if ((signed char)flags != ((signed char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x18]) {
                    ((signed char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x18] = flags;
                    fn_800557A8();
                }
                self->result = 15;
                self->mode = 3;
                return 2;
            }
        } else if (flags & 0x20) {
            flags = self->count;
            if ((signed char)flags != ((signed char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x18]) {
                ((signed char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x18] = flags;
                fn_800557A8();
            }
            for (int i = 0; i < 2; ++i)
                fn_800B330C(self->objects->items[i], lbl_2_data_20D0 + 0x64, 1);
            self->result = 5;
            self->mode = 3;
            return 1;
        }
        break;
    }
    case 3:
        if (ro[0] == ((Object**)self->objects)[self->selection + 0x56]->anim->getUpdateRate())
            return 3;
        break;
    }
    return 0;
}