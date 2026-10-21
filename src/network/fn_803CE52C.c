#pragma force_active on
extern void OSCancelAlarm(void* alarm);
extern int fn_803CD3B4(unsigned short arg0);

void fn_803CE52C(void) {
    unsigned int i;

    i = 0;
    do {
        OSCancelAlarm((void*)(fn_803CD3B4((unsigned short)i) + 0x198));
        i += 1;
    } while (i < 2);
}
