#include <so/kinetic/so_kinetic_energy.h>

struct PikachuPoolFlag;
extern "C" PikachuPoolFlag* fn_98_CD20(PikachuPoolFlag*, const short&);
extern "C" PikachuPoolFlag* fn_98_E208(PikachuPoolFlag*, const PikachuPoolFlag&);

// Each pool receives its own copy of the mediator's two-byte mask.
struct PikachuPoolFlag {
    short mask;
};

extern "C" {
void fn_98_E170(void*, const PikachuPoolFlag&, soModuleAccesser*);
void fn_98_DED4(void*, const PikachuPoolFlag&, soModuleAccesser*);
void fn_98_DC38(void*, const PikachuPoolFlag&, soModuleAccesser*);
void fn_98_D99C(void*, const PikachuPoolFlag&, soModuleAccesser*);
void fn_98_D700(void*, const PikachuPoolFlag&, soModuleAccesser*);
void fn_98_D464(void*, const PikachuPoolFlag&, soModuleAccesser*);
void fn_98_D1CC(void*, const PikachuPoolFlag&, soModuleAccesser*);
void fn_98_CF30(void*, const PikachuPoolFlag&, soModuleAccesser*);
}

extern "C" void fn_98_C948(void* mediator, soModuleAccesser* accesser,
    const soKineticEnergy::AttributeFlag& attributes) {
    char* pools = static_cast<char*>(mediator);
    PikachuPoolFlag flags;
    short mask = attributes.m_signedMask;
    PikachuPoolFlag pool1CC, pool138, pool98, pool8;
    PikachuPoolFlag pool64, poolF0, pool180, pool208;
    fn_98_CD20(&flags, mask);
    fn_98_E208(&pool208, flags);
    fn_98_E170(pools + 0x208, pool208, accesser);
    fn_98_E208(&pool1CC, flags);
    fn_98_DED4(pools + 0x1cc, pool1CC, accesser);
    fn_98_E208(&pool180, flags);
    fn_98_DC38(pools + 0x180, pool180, accesser);
    fn_98_E208(&pool138, flags);
    fn_98_D99C(pools + 0x138, pool138, accesser);
    fn_98_E208(&poolF0, flags);
    fn_98_D700(pools + 0xf0, poolF0, accesser);
    fn_98_E208(&pool98, flags);
    fn_98_D464(pools + 0x98, pool98, accesser);
    fn_98_E208(&pool64, flags);
    fn_98_D1CC(pools + 0x64, pool64, accesser);
    fn_98_E208(&pool8, flags);
    fn_98_CF30(pools + 0x8, pool8, accesser);
}
