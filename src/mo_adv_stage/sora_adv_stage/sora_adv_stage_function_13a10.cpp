#include <em/em_manager.h>
#include <em/em_external_value_accesser.h>
#include <em/enemy.h>
#include <gf/gf_camera.h>
#include <ec/ec_mgr.h>
#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

struct EffectBounds { float x, y, z, w; };
struct EffectArgs { char pad[4]; Enemy* enemy; u32 id; };
extern "C" bool fn_41_D0A8(emManager*, u32);
extern "C" bool fn_80019C10(gfCameraManager*, EffectBounds*);
extern const float lbl_40_rodata_1B0[];
extern ecMgr* g_ecMgr;

extern "C" void fn_40_13A10(void* self, EffectArgs* args) {
    const float* rodata = lbl_40_rodata_1B0;
    void* object = *(void**)((char*)self + 0x90);
    u16 kind = *(u16*)((char*)object + 0x1C);
    if (kind >= 0x2E || kind == 0x15 || kind == 0x16 || kind == 0x1A ||
        kind == 0x0C || kind == 0x14 || kind == 0x24 || kind == 0x0D ||
        kind == 0x2B || kind == 0x2C || kind == 0x0E || kind == 0x10) return;
    emManager* manager = emManager::getInstance();
    if (!fn_41_D0A8(manager, args->id)) return;
    Vec3f position;
    Vec3f zero;
    Vec3f scale;
    EffectBounds bounds;
    Vec3f center = emExternalValueAccesser::getCenterPos(args->enemy);
    position.m_x = center.m_x;
    position.m_y = center.m_y;
    position.m_z = center.m_z;
    bounds.x = center.m_x;
    bounds.y = center.m_y;
    bounds.z = rodata[0];
    bounds.w = rodata[9];
    if (!fn_80019C10(gfCameraManager::getManager(), &bounds)) return;
    float size;
    switch (kind) {
    case 16: size = rodata[10]; break;
    case 10: size = rodata[11]; break;
    case 11: case 42: size = rodata[12]; break;
    case 8: size = rodata[13]; break;
    case 18: case 24: size = rodata[14]; break;
    case 6: case 15: size = rodata[15]; break;
    default: size = rodata[8]; break;
    }
    float scaleValues[3];
    float zeroValues[3];
    scaleValues[0] = size;
    scaleValues[1] = size;
    scaleValues[2] = size;
    scale.m_x = scaleValues[0];
    scale.m_y = scaleValues[1];
    scale.m_z = scaleValues[2];
    zeroValues[0] = rodata[0];
    zeroValues[1] = rodata[0];
    zeroValues[2] = rodata[0];
    zero.m_x = zeroValues[0];
    zero.m_y = zeroValues[1];
    zero.m_z = zeroValues[2];
    g_ecMgr->setEffect((EfID)0x01030007, &position, &zero, &scale);
}