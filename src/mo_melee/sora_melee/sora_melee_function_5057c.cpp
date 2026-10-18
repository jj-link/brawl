#include <StaticAssert.h>
#include <so/event/so_event_presenter.h>
#include <types.h>
#pragma force_active on

// Id pair of one of the event system's Null instances: the observer id and
// the slot id, both invalidated together by the original routine.
struct soEventObserverNullIds {
    void* vptr;
    u32 m_ids;
};
static_assert(sizeof(soEventObserverNullIds) == 8, "Class is wrong size!");

// Invalidate the id pair of the object handed in r3.
extern "C" void fn_27_5057C(soEventObserverNullIds* ids) {
    ids->m_ids = 0xFFFFFFFF;
}
