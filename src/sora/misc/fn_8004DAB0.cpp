#pragma force_active on

extern "C" void fn_8004DAB0(char* self, int off, char val) {
    char* base = *(char**)(self + 0x24);
    char* field = (char*)((unsigned int)base + 0x810);
    field = (char*)((unsigned int)field + off);
    *(field + 0x10) = val;
}
