namespace {
struct DededeParameterBindings {
    void* vtable;
    unsigned char active;
    unsigned char padding05[3];
    void* baseVtable;
    int kind;
    int firstParameter;
    int lastParameter;
    int state;
    void* fields1C[8];
    unsigned char reserved3C[0x50];
    void* fields8C[6];
    unsigned char reservedA4[0x30];
    void* entriesVtable;
    int entryState;
    void* entries;
    int entryCount;
};
}

extern "C" {
extern unsigned char lbl_117_data_93F4[];
extern unsigned char lbl_117_data_94AC[];

// Bind the parameter groups and the optional three-entry table without clearing
// the other, independently initialized members of the enclosing module.
void fn_117_1799C(void* object, void* parameters, void* entries) {
    DededeParameterBindings* bindings = static_cast<DededeParameterBindings*>(object);
    unsigned char* fields = static_cast<unsigned char*>(parameters);
    bindings->active = 0;
    bindings->kind = 0x33;
    bindings->firstParameter = 0xF9F;
    bindings->lastParameter = 0x5DBF;
    bindings->state = 0;
    bindings->baseVtable = lbl_117_data_93F4;
    bindings->vtable = lbl_117_data_93F4 + 8;
    bindings->entryState = 0;
    bindings->entriesVtable = lbl_117_data_94AC;
    bindings->entries = entries;
    bindings->entryCount = 3;
    if (entries == 0) {
        bindings->entryCount = 0;
    }
    bindings->fields1C[0] = fields + 0x0C;
    bindings->fields1C[1] = fields + 0x10;
    bindings->fields1C[2] = fields + 0x14;
    bindings->fields1C[3] = fields + 0x18;
    bindings->fields1C[4] = fields + 0x24;
    bindings->fields1C[5] = fields + 0x28;
    bindings->fields1C[6] = fields + 0x30;
    bindings->fields1C[7] = fields + 0x34;
    bindings->fields8C[0] = fields;
    bindings->fields8C[1] = fields + 4;
    bindings->fields8C[2] = fields + 8;
    bindings->fields8C[3] = fields + 0x1C;
    bindings->fields8C[4] = fields + 0x20;
    bindings->fields8C[5] = fields + 0x2C;
}
}
