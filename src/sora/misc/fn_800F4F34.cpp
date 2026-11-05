#include <gf/gf_archive.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" const float lbl_805A2610;

struct Entry {
    ARCNodeType type;
    int file;
    int texture;
    int object;
    int priority;
    const char* name;
};
struct ObjectSlot {
    MuObject* object;
    int unused;
};
struct State {
    char pad[0x40];
    gfArchive* archive;
    nw4r::g3d::ResFile files[16];
    int count;
    char pad88[0xc];
    int priority;
    char pad98[4];
    ObjectSlot objects[1];
};
extern "C" void fn_800F4F34(State* self, Entry* entries, int count) {
    if (!self->archive || !entries || count <= 0) return;
    {
        Entry* p = entries;
        for (int i = 0; i < count; ++p, ++i) {
            void* data = self->archive->getData(p->type, p->file, 0xfffe);
            int index;
            if (!data) {
                index = -1;
            } else {
                index = self->count;
                nw4r::g3d::ResFile* file = &self->files[index];
                *file = nw4r::g3d::ResFile(data);
                nw4r::g3d::ResFile::Init(file);
                self->count++;
            }
            if (p->object != -1) {
                nw4r::g3d::ResFile* texture = 0;
                if (p->texture >= 0)
                    texture = &self->files[p->texture];
                self->objects[p->object].object = MuObject::create(&self->files[index], p->name, p->priority + self->priority, texture, (HeapType)15);
                self->objects[p->object].object->changeAnimN(p->name);
                self->objects[p->object].object->m_modelAnim->setUpdateRate(lbl_805A2610);
            }
        }
    }
}