#pragma force_active on
#pragma peephole off
extern "C" void fn_8015D00C(void*);
extern "C" void fn_8015D4CC(void* self) {
 fn_8015D00C(self);
 *((signed char*)self + 111) = 0;
}
