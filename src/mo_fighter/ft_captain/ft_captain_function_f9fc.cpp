#include <so/so_external_value_accesser.h>
#pragma force_active on

struct Entry {
    unsigned int id;
    int slot;
    int unused;
    int status;
    int situation;
    Vec3f pos;
    float lr;
    unsigned char active : 1;
};
struct Context {
    char pad[8];
    StageObject* object;
};
extern "C" bool fn_100_FAD4(unsigned int, void*);
extern "C" int fn_100_F850(void*, unsigned int);
extern "C" void fn_100_E184(Vec3f*, const Vec3f*);

extern "C" bool fn_100_F9FC(Context* self, Entry* entry, StageObject* object) {
    unsigned int ownId = self->object->m_taskId;
    if (object) {
        unsigned int id = object->m_taskId;
        if (id != ownId && !fn_100_FAD4(id, self)) {
            entry->id = id;
            entry->slot = fn_100_F850(self, id);
            entry->status = soExternalValueAccesser::getStatusKind(object);
            entry->situation = soExternalValueAccesser::getSituationKind(object);
            Vec3f pos = soExternalValueAccesser::getPos(object);
            fn_100_E184(&entry->pos, &pos);
            entry->lr = soExternalValueAccesser::getLr(object);
            entry->unused = 0;
            entry->active = 0;
            return true;
        }
    }
    return false;
}