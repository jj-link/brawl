#include <types.h>
#pragma force_active on

#include <em/em_info.h>
#include <so/so_archive_db.h>

extern "C" void* fn_800455E0(void*, int);

struct SoEnemyModule {
    void* arr[6];
};

extern "C" SoEnemyModule* fn_41_D8D4(SoEnemyModule* this_, int a, int b, int c, int d, emKind kind)
{
    this_->arr[0] = (void*)0xFFFF;
    this_->arr[1] = (void*)0xFFFF;
    this_->arr[2] = (void*)0xFFFF;
    this_->arr[3] = (void*)0xFFFF;
    this_->arr[4] = (void*)0xFFFF;
    this_->arr[5] = (void*)0xFFFF;
    this_->arr[2] = fn_800455E0(soArchiveDb::getManager(1), a);
    this_->arr[1] = fn_800455E0(soArchiveDb::getManager(1), b);
    this_->arr[0] = fn_800455E0(soArchiveDb::getManager(1), c);
    this_->arr[4] = this_->arr[1];
    this_->arr[3] = this_->arr[1];
    if (emInfo::getInstance()->isPrimKind(kind) == 1U) {
        this_->arr[5] = fn_800455E0(soArchiveDb::getManager(1), d);
    }
    return this_;
}