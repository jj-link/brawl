#pragma force_active on
extern "C" {

struct S { char pad[0x190]; int count; };
extern S* lbl_80497780[10];

void fn_80038890(void) {
    S* obj;
    for (unsigned short i = 0; i < 10; i++) {
        obj = lbl_80497780[i];
        if (obj) {
            obj->count++;
            return;
        }
    }
}

}
