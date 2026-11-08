#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0(int, int, int);
};
struct Holder {
    char pad[8];
    Object_vptr_0* callback;
};
extern "C" {
u32 getLanguage__10GameGlobalFv(GameGlobal*);
int fn_8014FDF0();
int fn_8014DD34(void*, int);
int fn_8014D624(void*, void*, unsigned short, int*);
int fn_8014E0DC(void*, int);
int fn_80150594();
unsigned int fn_801505C0();
int fn_803A3324(void*);
int fn_803A3D64(void*);
int fn_803A2C58(void*, unsigned short);
int fn_803A31D0(void*, short);
int fn_803A38C0(void*);
extern u8 lbl_8059E7D8[8];
extern char* lbl_80460F04[];
extern unsigned short lbl_8059E7D4;
extern short lbl_8059E7D2;
}
extern "C" int fn_8014D854(Holder* self) {
    char buffer[0x200];
    int result;
    u32 lang = getLanguage__10GameGlobalFv(g_GameGlobal);
    if (lang >= 7) lang = 0;
    unsigned short index = lbl_8059E7D8[lang];
    if (index == 0x11) index = 1;
    if (index >= 0x11 || !lbl_80460F04[index][0]) return 0;
    if (!fn_8014FDF0()) return 0;
    if (!fn_8014DD34(self, 1)) return 0;
    result = fn_803A3324(buffer);
    if (result == -13) {
        if (!fn_8014D624(self, buffer, index, &result)) {
            if (fn_8014E0DC(self, result)) {
                Object_vptr_0* cb = self->callback;
                int code = result;
                if (cb) cb->slot0(3, code, 0x1ADAF);
            }
            return 0;
        }
        result = fn_803A3D64(buffer);
        if (result) {
            if (fn_8014E0DC(self, result)) {
                if (!fn_80150594() && fn_801505C0() == 1) {
                    Object_vptr_0* cb = self->callback;
                int code = result;
                    if (cb) cb->slot0(6, code, 0x1AA58);
                } else {
                    Object_vptr_0* cb = self->callback;
                int code = result;
                    if (cb) cb->slot0(3, code, 0x1ADAF);
                }
            }
            return 0;
        }
    } else {
        if (result) {
            if (fn_8014E0DC(self, result)) {
                Object_vptr_0* cb = self->callback;
                int code = result;
                if (cb) cb->slot0(3, code, 0x1ADAF);
            }
            return 0;
        }
        result = fn_803A2C58(buffer, lbl_8059E7D4);
        if (result) {
            if (fn_8014E0DC(self, result)) {
                Object_vptr_0* cb = self->callback;
                int code = result;
                if (cb) cb->slot0(3, code, 0x1ADAF);
            }
            return 0;
        }
        result = fn_803A31D0(buffer, lbl_8059E7D2);
        if (result) {
            if (fn_8014E0DC(self, result)) {
                Object_vptr_0* cb = self->callback;
                int code = result;
                if (cb) cb->slot0(3, code, 0x1ADAF);
            }
            return 0;
        }
        result = fn_803A38C0(buffer);
        if (result) {
            if (fn_8014E0DC(self, result)) {
                if (!fn_80150594() && fn_801505C0() == 1) {
                    Object_vptr_0* cb = self->callback;
                int code = result;
                    if (cb) cb->slot0(6, code, 0x1AA58);
                } else {
                    Object_vptr_0* cb = self->callback;
                int code = result;
                    if (cb) cb->slot0(3, code, 0x1ADAF);
                }
            }
            return 0;
        }
    }
    return 1;
}