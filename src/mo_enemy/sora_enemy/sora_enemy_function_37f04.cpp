#include <it/it_manager.h>
#include <mt/mt_trig.h>
#include <so/model/so_model_module_impl.h>
#include <revolution/os.h>
#pragma force_active on


class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5(int, unsigned int);
};
struct Outer {
 char pad[4];
 soModelModule* query;
 char pad2[0x5c];
 Object_vptr_0* target;
};
struct Inner { char pad[0x28]; int ownerId; };
struct EnemyData {
 char pad[0xdc];
 char accesser[8];
 Inner* inner;
 char pad2[0xcc];
 Outer* outer;
};
struct SpawnData { char pad[0x18]; int mode; float x,y,z; };
extern "C" {
itManager* getInstance__9itManagerFv(Inner*);
void fn_27_28F6BC(BaseItem*, float*, int);
float fn_41_6A68(float*, void*);
float fn_41_6AD8(void*, void*);
extern const float lbl_41_rodata_EA8;
extern const float lbl_41_rodata_EAC;
extern const char lbl_41_data_8518[];
}
extern "C" int fn_41_37F04(EnemyData* self, itKind kind, unsigned int variation, SpawnData* spawn) {
 Vec3f position;
 Vec3f spawnPos;
 Vec3f dir;
 if (!itManager::getInstance()->isCompItemKindArchive(kind, 0, true)) {
  itManager::getInstance()->preloadItemKindArchive(kind, 0, (itArchive::Type)0, true);
  return 1;
 }
 Inner* inner = self->inner;
 int ownerId = inner->ownerId;
 itManager* manager = getInstance__9itManagerFv(inner);
 BaseItem* item = manager->createItem(kind, variation, ownerId, 0, 0, 0xffff, 0, 0xffff);
 if (item != 0) {
  soModelModule* query = self->outer->query;
  spawnPos.m_x = spawn->x;
  spawnPos.m_y = spawn->y;
  spawnPos.m_z = spawn->z;
  Vec3f temp = query->getNodeGlobalPosition(spawn->mode, &spawnPos != 0);
  position.m_x = temp.m_x;
  position.m_y = temp.m_y;
  position.m_z = temp.m_z;
  mtSinCosf(lbl_41_rodata_EA8 * fn_41_6AD8((char*)spawn + 8, self->accesser), &dir.m_y, &dir.m_x);
  float scale = fn_41_6A68((float*)spawn, self->accesser);
  dir.m_x *= scale;
  dir.m_y *= scale;
  dir.m_z = lbl_41_rodata_EAC;
  item->warp(&position);
  item->updateNodeSRT();
  fn_27_28F6BC(item, &dir.m_x, 1);
  self->outer->target->slot5(*(int*)((char*)item + 0x8bc), 0x1000000f);
 } else {
  OSReport(lbl_41_data_8518);
  return 0;
 }
 return 1;
}