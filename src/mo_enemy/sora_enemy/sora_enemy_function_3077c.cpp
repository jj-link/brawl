#include <types.h>
#include <so/event/so_event_presenter.h>
#include <ut/ut_list.h>
#include <wn/wn_weapon_builder.h>
#include <wn/wn_em_simple.h>
#pragma force_active on

void wnemSimple::RequestDeactive() {
    unk2219[0] = 1;
}
