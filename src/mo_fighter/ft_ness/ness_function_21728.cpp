#pragma force_active on
// Ness's energy-view constructor: installs the module's shared vtable.
// The caller discards the result, so the tail branch is never taken and
// the whole sequence folds into a single lis/addi/stw pair.
extern "C" unsigned char lbl_101_data_BBE8[];

#pragma dont_inline on
extern "C" void fn_101_21728(void* object) {
    *reinterpret_cast<unsigned char**>(object) = lbl_101_data_BBE8;
}
#pragma dont_inline reset
