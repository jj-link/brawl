#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on
extern "C" int fn_800797A4(snd3DGenerator*, int);
struct Entry { unsigned char state; unsigned char pad[3]; Vec3f pos; unsigned char rest[0x2c]; };
struct Sound { snd3DGenerator generator; int handle; unsigned char index; unsigned char pad[3]; };
struct Object {
    char pad0[0x9c]; int active; char pad1[0x374 - 0xa0];
    Entry entries[30]; unsigned char indices[5]; char pad3[0xaa0 - 0xa81]; Sound sounds[5];
};
extern "C" void fn_81_21EC(Object* self) {
    if (self->active) {
        Object* p;
        unsigned int i = 0;
        while (i != 5) {
            p = (Object*)((char*)self + i * 0x10);
            if (p->sounds[0].handle != -1) {
                if (!fn_800797A4(&p->sounds[0].generator, p->sounds[0].handle))
                    p->sounds[0].handle = -1;
            }
            if (p->sounds[0].handle == -1) {
                i++;
                continue;
            }
            Entry* entry = &self->entries[self->indices[p->sounds[0].index]];
            switch (entry->state) {
            case 8:
                if (p->sounds[0].handle != -1)
                    self->sounds[i].generator.stopSE(p->sounds[0].handle, 0x78);
                break;
            case 4: case 5: case 6: case 7:
                self->sounds[i].generator.setPos(&entry->pos);
                break;
            }
            i++;
        }
    }
}