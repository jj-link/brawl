#pragma force_active on
extern "C" void fn_40_30AFC(unsigned int* self, unsigned int value) { self[2] = __rlwimi(self[2], value, 27, 0, 4); }