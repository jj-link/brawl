#include <ms/ms_message.h>
#pragma force_active on
extern "C" void fn_8006BCA8(char*, const void*);
struct NameSlot { unsigned char pad0[0xE0]; unsigned short used; unsigned char raw[10]; unsigned char pad1[0x38]; };
struct Manager { unsigned char pad[0x28]; NameSlot* slots; unsigned char pad2[4]; unsigned char* data; };
struct Output { int name; int data; };
struct Name { int magic; unsigned char flag; unsigned char pad; wchar_t text[1]; };
static inline int getName(NameSlot* slot, void* out) {
    if (slot->used == 0) return 0;
    memcpy(out, &slot->used, 12);
    return 1;
}
extern "C" void fn_8004F168(Manager* mgr, Output* output) {
    output->name = 8;
    output->data = 0x20;
    memcpy((char*)output + 0x20, mgr->data, 0x4910);
    Name* name = (Name*)((char*)output + output->name);
    name->magic = 0x07092000;
    name->flag = 1;
    unsigned short raw[6];
    char buf[21] = {0};
    if (mgr->data[0x600] < 120) {
        if (getName(mgr->slots + mgr->data[0x600], raw))
            fn_8006BCA8(buf, raw);
    }
    Message::utf8to16(name->text, buf);
}