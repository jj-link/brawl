#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

struct Entry {
    char pad0[0x90];
    char name[0x110];
    int id;
    char pad1[0x5c];
    int disabled;
};

struct List {
    Entry** entries;
    int count;
    char pad[5];
    unsigned char flag;
    char pad2[0x12];
    unsigned char multiple;

    int getId(int i) {
        if (i < count)
            return entries[i]->id;
        return entries[(int)((unsigned)count - 1)]->id;
    }
};

struct Self {
    List* first;
    List* second;
};

extern "C" int fn_8008DFDC(Self* self, int* output, nw4r::g3d::ResMdl* model) {
    int* out;
    int count = 0;

    if (self->first->multiple) {
        if (self->first->flag) {
            for (int i = self->first->count - 1; i >= 0; --i) {
                Entry* entry = self->first->entries[i];
                if (entry->disabled == 0) {
                    output[count] = self->first->getId(i);
                    ++count;
                }
            }
        } else {
            out = output;
            for (int i = self->first->count - 1; i >= 0; --i) {
                Entry* entry = self->first->entries[i];
                if (entry->disabled == 0) {
                    nw4r::g3d::ResNode node = model->GetResNode(entry->name);
                    *out++ = node.IsValid() ? node->m_nodeIndex : 0;
                    ++count;
                }
            }
        }
    } else {
        int i = self->first->count - 1;
        if (self->first->flag) {
            *output = self->first->getId(i);
        } else {
            nw4r::g3d::ResNode node = model->GetResNode(self->first->entries[i]->name);
            *output = node.IsValid() ? node->m_nodeIndex : 0;
        }
        count = 1;
    }

    if (self->second->multiple) {
        if (self->second->flag) {
            for (int i = self->second->count - 1; i >= 0; --i) {
                Entry* entry = self->second->entries[i];
                if (entry->disabled == 0) {
                    output[count] = self->second->getId(i);
                    ++count;
                }
            }
        } else {
            out = output + count;
            for (int i = self->second->count - 1; i >= 0; --i) {
                Entry* entry = self->second->entries[i];
                if (entry->disabled == 0) {
                    nw4r::g3d::ResNode node = model->GetResNode(entry->name);
                    *out++ = node.IsValid() ? node->m_nodeIndex : 0;
                    ++count;
                }
            }
        }
    } else {
        int i = self->second->count - 1;
        if (self->second->flag) {
            output[count] = self->second->getId(i);
        } else {
            nw4r::g3d::ResNode node = model->GetResNode(self->second->entries[i]->name);
            output[count] = node.IsValid() ? node->m_nodeIndex : 0;
        }
        ++count;
    }

    return count;
}
