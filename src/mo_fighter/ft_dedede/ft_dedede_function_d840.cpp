class soKineticMediatorImpl;

// Virtual soKineticMediatorImpl getEnergyNum: return the mediator's fixed
// kinetic-energy count (8 pooled energy types: motion, gravity, controller,
// stop, damage, wind, ground movement, jostle); the soKineticMediatorNull
// counterpart returns 0 (cf. fn_99_1096C).
extern "C" int fn_117_D840(soKineticMediatorImpl*) {
    return 8;
}
