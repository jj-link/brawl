#include <so/model/so_model_module_simple.h>
#pragma force_active on
extern "C" const float lbl_27_rodata_C5C;
struct Entry { int id; float x,y,z; int extra; };
template <class T> struct List { T* data; unsigned count; };
struct Owner {
 char pad[0x44]; char* access;
 char pad48[8]; List<int>* ids; unsigned index;
 char pad58[8]; List<Entry>* entries; unsigned entryIndex;
};
extern "C" int fn_27_97D84(Owner* self, int id, Vec3f* out) {
 out->m_x = out->m_y = out->m_z = lbl_27_rodata_C5C;
 switch(id) {
 case -1: {
 id = self->ids->data[self->index];
 if (++self->index >= self->ids->count) self->index = 0;
 return id;
 }
 case -2: {
 Entry* entry = &self->entries->data[self->entryIndex];
 int result = entry->id;
 out->m_x = entry->x; out->m_y = entry->y; out->m_z = entry->z;
 if (++self->entryIndex >= self->entries->count) self->entryIndex = 0;
 return result;
 }
 default:
 return (*(soModelModule***)(self->access + 0xd8))[1]->getCorrectNodeId(id);
 }
}
