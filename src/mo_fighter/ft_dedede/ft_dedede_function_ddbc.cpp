// Mediator stub callback: ignores the mediator entry, the stack copy of the
// event mask and the event it is invoked with, and always reports zero.
// fn_117_DD2C calls this with (entry + 4, stack mask copy, event) and ignores
// the result; fn_117_DDC4 is the checking variant in the same family.
extern "C" int fn_117_DDBC(void* entry, void* mask, void* event) {
    return 0;
}
