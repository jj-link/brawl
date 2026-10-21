#pragma force_active on
// main/gf_pad_system.c
// gfPadSystem::merge(gfPadStatus*, int, gfPadStatus*)
// Forwards to gfPadSystem::merge(gfPadStatus*, int, u32, gfPadStatus*) with the
// pad/motor mask defaulted to 0xffff.

extern "C" void merge__11gfPadSystemFP11gfPadStatusiUlP11gfPadStatus(
    void* src, int numPads, unsigned long mask, void* dest);

extern "C" void merge__11gfPadSystemFP11gfPadStatusiP11gfPadStatus(
    void* src, int numPads, void* dest) {
    merge__11gfPadSystemFP11gfPadStatusiUlP11gfPadStatus(src, numPads, 0xffff, dest);
}
