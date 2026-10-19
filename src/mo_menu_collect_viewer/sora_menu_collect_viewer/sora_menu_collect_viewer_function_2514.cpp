#pragma force_active on
struct Entry { void* pad[0]; };
struct Obj {
    unsigned char pad[0x1ac];
    unsigned char* table;
};

extern "C" void* fn_6_2514(Obj* obj, int index) {
    return *(void**)(obj->table + index * 16 + 0x1a8);
}
