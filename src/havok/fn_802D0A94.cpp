#pragma force_active on
extern "C" {
extern char lbl_804873E8[];
extern char lbl_80487488[];

void fn_802D0A94(void *arg0)
{
    if (arg0 != 0) {
        *(unsigned short *)((char *)arg0 + 6) = 1;
        *(void **)arg0 = (void *)lbl_80487488;
        *(void **)((char *)arg0 + 0x10) = (void *)lbl_804873E8;
    }
}
}
