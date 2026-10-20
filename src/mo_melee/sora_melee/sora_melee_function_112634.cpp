#pragma force_active on
struct ModuleTable { void* data[1024]; };
struct ModuleHolder { ModuleTable* table; };
extern "C" void* fn_27_112634(ModuleHolder* h) { return h->table->data[0x804 / sizeof(void*)]; }
