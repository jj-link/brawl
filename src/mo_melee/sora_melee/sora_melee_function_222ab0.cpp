#include <gf/gf_archive.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_data.h>
#include <st/stage.h>
#include <types.h>
#pragma force_active on

grCollision* Stage::createCollision(gfArchive* archive, int index, Ground* ground) {
    grCollision* result;
    if (!archive) {
        return nullptr;
    }
    grCollData* collData = new (Heaps::StageInstance) grCollData;
    if (!collData) {
        return nullptr;
    }
    testCollDataInit(archive, collData, index);
    result = grCollision::create(this, collData, ground, 1);
    delete collData;
    return result;
}
