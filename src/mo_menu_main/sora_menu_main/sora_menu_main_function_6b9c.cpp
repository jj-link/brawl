#include <gf/gf_model.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <string.h>
#include <types.h>
#pragma force_active on

typedef struct Entry {
    const char* name;
    u16 idxBegin;
    u16 idxEnd;
    u8 drawPriority;
    u8 flags;
} Entry;

extern "C" {
extern char lbl_2_data_D0C[];
extern float lbl_2_rodata_18C;
MuObject* fn_800B74CC(nw4r::g3d::ResFile* modelSource, const char* modelNode, u8 drawPriority, nw4r::g3d::ResFile* textureSource, HeapType type);

void fn_2_6B9C(u8* arg0, Entry* arg1, s32 arg2, nw4r::g3d::ResFile* arg3) {
    char buf[0x40];
    s32 i;
    Entry* e;
    MuObject* obj;
    s32 j;
    s32 n;
    u8* slot;
    const char* name;
    e = arg1;
    for (i = 0; i < arg2; i++, e++) {
        n = (e->idxBegin < e->idxEnd) ? (e->idxEnd - e->idxBegin) : 1;
        for (j = 0; j < n; j++) {
            if ((e->flags >> 7) & 1) {
                obj = MuObject::create(arg3, e->name, e->drawPriority, 0, (HeapType)0x2a);
            } else {
                obj = fn_800B74CC(arg3, e->name, e->drawPriority, 0, (HeapType)0x2a);
            }
            name = e->name;
            slot = *(u8**)(arg0 + 0x40) + ((e->idxBegin + j) << 2);
            *(MuObject**)(slot + 0x114) = obj;
            strcpy(buf, name);
            strcat(buf, lbl_2_data_D0C);
            obj->changeAnimN(buf);
            if (obj->m_modelAnim != 0) {
                obj->m_modelAnim->setUpdateRate(lbl_2_rodata_18C);
            }
        }
    }
}
}
