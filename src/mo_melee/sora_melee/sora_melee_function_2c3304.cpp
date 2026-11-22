#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on
struct Entry { const char* name; u8 begin; u8 end; u8 arg; };
struct Owner { char pad[0x54]; MuObject* objs[64]; };
extern "C" {
extern Entry lbl_27_rodata_6010[];
extern const f32 lbl_27_rodata_6018;
}
inline void work(Owner* self, nw4r::g3d::ResFile* resFile, int kindOffset, const Entry* table) {
    for (int j = 0; j < 1; ++j) {
        const Entry* e = &table[j];
        int i;
        u32 end = e->end;
        u32 begin = e->begin;
        int n = 1;
        if (begin < end)
            n = end - begin;
        for (i = 0; i < n; ++i) {
            self->objs[e->begin + i] =
                MuObject::create(resFile, e->name, e->arg + kindOffset, 0, (HeapType)0x1f);
            self->objs[e->begin + i]->m_modelAnim->setUpdateRate(lbl_27_rodata_6018);
        }
    }
}
extern "C" void fn_27_2C3304(Owner* self, nw4r::g3d::ResFile* resFile, int kindOffset) {
    work(self, resFile, kindOffset, lbl_27_rodata_6010);
}