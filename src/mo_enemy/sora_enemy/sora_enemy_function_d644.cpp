#pragma force_active on
struct Owner;

extern "C" void* fn_41_D5A0(Owner* self, unsigned int index);

extern "C" int fn_41_D644(Owner* self) {
    unsigned int i = 0;
    while (i < *(unsigned int*)((unsigned char*)self + 0xc)) {
        unsigned char* e = (unsigned char*)fn_41_D5A0(self, i);
        if (e != 0 && *e == 0) {
            return i;
        }
        i++;
    }
    return -1;
}
