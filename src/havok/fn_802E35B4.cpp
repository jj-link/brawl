#pragma force_active on
extern "C" {

struct Struct_80532FF8 {
    void* field0;
    void* field1;
    void* field2;
    void* field3;
};

extern struct Struct_80532FF8 lbl_80532FF8;
extern char lbl_80412CE0[];
extern void fn_802E22C4();
extern void fn_802E2310();
extern void* fn_802E2324();

void fn_802E35B4() {
    void* r = fn_802E2324();
    lbl_80532FF8.field0 = &lbl_80412CE0;
    lbl_80532FF8.field1 = fn_802E22C4;
    lbl_80532FF8.field2 = fn_802E2310;
    lbl_80532FF8.field3 = r;
}

}

__declspec(section ".ctors") extern void* const fn_802E35B4_ctor = (void*)fn_802E35B4;
