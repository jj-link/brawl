#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" float randf__Fv();

extern const float lbl_41_rodata_D98;
extern const float lbl_41_rodata_D9C;

class VObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(u32 a, void* b, float f);
    virtual void slot5(u32 idx, u32 id);
    virtual void slot6();
    virtual void slot7(u32 a, s32 b, void* c);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(u32 id);
    virtual void slot13(float v, u32 id);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual u32 slot17(u32 id);
    virtual void slot18();
    virtual void slot19(u32 id);
};

struct Sub {
    char pad0[0x64];
    VObj* obj64;
    char pad1[4];
    VObj* obj6c;
};

struct Mid {
    char pad[0xd8];
    Sub* sub;
};

struct Self {
    char pad0[0x18];
    Mid* mid;
    char pad1[0x10];
    u32 unk2C;
};

struct Entry {
    s32 a;
    float b;
    s32 c;
};

extern "C" s32 fn_41_2988C(Self* self, Entry* entries, u32 count) {
    s32 idxs[32];
    float weights[32];
    s32 best = -1;
    s32 n = 0;
    float total = lbl_41_rodata_D9C;
    s32 i;
    s32 j;
    Entry* e;
    s32 flag;
    float f3;
    float f0;
    float f1;

    if (entries == 0) {
        return -1;
    }
    if (count > 0x20) {
        return -1;
    }
    if (count <= 1) {
        return -1;
    }
    for (j = 0; j < 32; j++) {
        idxs[j] = -1;
        weights[j] = lbl_41_rodata_D9C;
    }
    for (i = 0; (u32)i < count; i++) {
        e = &entries[i];
        f1 = soValueAccesser::getValueFloat(reinterpret_cast<soModuleAccesser*>(self->mid), 0x1100000C, 0);
        f3 = (float)(u32)e->a;
        if (lbl_41_rodata_D9C != e->b) {
            f3 += e->b * f1;
        }
        if (!(f3 < lbl_41_rodata_D9C)) {
            self->mid->sub->obj64->slot13(f3, 0x21000000);
            self->mid->sub->obj64->slot5(i, 0x20000006);
            flag = 0;
            if (e->c == 0) {
                flag = 1;
            } else {
                VObj* o = self->mid->sub->obj6c;
                self->mid->sub->obj64->slot19(0x22000004);
                o->slot7(self->unk2C, e->c, self->mid);
                o->slot4(self->unk2C, self->mid, lbl_41_rodata_D98);
                if (self->mid->sub->obj64->slot17(0x22000004) == 1) {
                    flag = 1;
                }
                o->slot7(self->unk2C, 0, self->mid);
            }
            float weight = self->mid->sub->obj64->slot12(0x21000000);
            weights[i] = weight;
            if (flag != 0 && !(weights[i] <= lbl_41_rodata_D9C)) {
                idxs[n] = i;
                total += weights[i];
                n++;
            }
        }
    }

    if (n == 0) {
        return -1;
    }
    if (n == 1) {
        best = idxs[0];
    } else {
        float r = total * randf__Fv();
        float acc = lbl_41_rodata_D9C;
        for (s32 k = 0; k < n; k++) {
            s32 idx = idxs[k];
            if (idx != -1) {
                acc += weights[idx];
                if (r < acc) {
                    best = idx;
                    break;
                }
            }
        }
    }
    return best;
}
