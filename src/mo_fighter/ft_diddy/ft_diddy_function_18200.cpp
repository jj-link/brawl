#pragma force_active on
extern "C" void fn_115_13100(void*, void*, void*);

extern "C" void fn_115_18200(void* object, void* context, void* argument) {
    fn_115_13100(context, static_cast<char*>(object) + 4, argument);
}
