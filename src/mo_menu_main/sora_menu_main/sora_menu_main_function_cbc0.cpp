#include <cm/cm_camera_controller.h>
#include <mu/mu_object.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_1_6D80(void*, void*);
void fn_800B6838(MuObject*, const Vec3f*);
extern const char lbl_2_data_1360[];
extern const char lbl_2_data_718[];
extern float lbl_2_rodata_2A0;
extern unsigned char lbl_2_rodata_38C[];
}
inline void setFlag(void* p) { *(int*)((char*)p + 12) = 1; }
struct Entry {
    float x;
    float y;
    char pad[12];
};
inline void setPosition(Vec3f* p, float x, float z) { p->m_x = x; p->m_y = lbl_2_rodata_2A0; p->m_z = z; }
struct Menu {
    char pad0[0x40];
    void* field40;
    char pad44[0x10];
    Entry entries[1];
    char pad68[0xe8 - 0x68];
    MuObject* objects[18];
    MuObject* object130;
    char pad134[0x48];
    void* field17c;
    char pad180[0xc4];
    int index;
};
extern "C" void fn_2_CBC0(Menu* self) {
    char* cam = (char*)CameraController::getInstance();
    setFlag(__dynamic_cast(*(void**)(cam + 0x48), 4, lbl_2_data_1360, lbl_2_data_718, 0));
    fn_1_6D80(self->field40, self->field17c);
    Entry* entry = &self->entries[self->index];
    Vec3f pos;
    float x = entry->x;
    float z = entry->y;
    setPosition(&pos, x, z);
    fn_800B6838(self->object130, &pos);
    float zero = lbl_2_rodata_2A0;
    MuObject* obj;
    unsigned char* p = lbl_2_rodata_38C;
    int i = 0;
    for (; i < 4; ++i, ++p) {
        obj = self->objects[*p];
        if (zero != obj->m_modelAnim->m_anmObjChrRes->GetUpdateRate()) {
            obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(zero);
            obj->setFrameNode(lbl_2_rodata_2A0);
        }
    }
}