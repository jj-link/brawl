#include <so/kinetic/so_kinetic_energy.h>
#include <types.h>

extern "C" s16* fn_114_FDD4(s16* destination, const s16* source);
extern "C" s16* fn_114_10520(s16* destination, const s16* source);
extern "C" void fn_114_10488(void* object, s16* state, soModuleAccesser* accesser);
extern "C" void fn_114_103A0(void* object, s16* state, soModuleAccesser* accesser);
extern "C" void fn_114_102B8(void* object, s16* state, soModuleAccesser* accesser);
extern "C" void fn_114_101D0(void* object, s16* state, soModuleAccesser* accesser);
extern "C" void fn_114_100E8(void* object, s16* state, soModuleAccesser* accesser);
extern "C" void fn_114_10000(void* object, s16* state, soModuleAccesser* accesser);
extern "C" void fn_114_FF18(void* object, s16* state, soModuleAccesser* accesser);
extern "C" void fn_114_FE30(void* object, s16* state, soModuleAccesser* accesser);

// Every specialization receives its own copied halfword state, in original order.
extern "C" void fn_114_FB98(void* object, soModuleAccesser* accesser, const s16* state) {
    s16 shared;
    s16 initial = *state;
    s16 gravity;
    s16 stop;
    s16 wind;
    s16 jostle;
    s16 ground;
    s16 damage;
    s16 controller;
    s16 motion;
    fn_114_FDD4(&shared, &initial);

    fn_114_10520(&motion, &shared);
    fn_114_10488(static_cast<char*>(object) + 0x208, &motion, accesser);
    fn_114_10520(&gravity, &shared);
    fn_114_103A0(static_cast<char*>(object) + 0x1cc, &gravity, accesser);
    fn_114_10520(&controller, &shared);
    fn_114_102B8(static_cast<char*>(object) + 0x180, &controller, accesser);
    fn_114_10520(&stop, &shared);
    fn_114_101D0(static_cast<char*>(object) + 0x138, &stop, accesser);
    fn_114_10520(&damage, &shared);
    fn_114_100E8(static_cast<char*>(object) + 0xf0, &damage, accesser);
    fn_114_10520(&wind, &shared);
    fn_114_10000(static_cast<char*>(object) + 0x98, &wind, accesser);
    fn_114_10520(&ground, &shared);
    fn_114_FF18(static_cast<char*>(object) + 0x64, &ground, accesser);
    fn_114_10520(&jostle, &shared);
    fn_114_FE30(static_cast<char*>(object) + 8, &jostle, accesser);
}
