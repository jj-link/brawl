#pragma force_active on
extern "C" {
extern char lbl_804873C0[];
extern char lbl_804873E8[];

void fn_802CE5F0(void *arg0)
{
    if (arg0 != 0) {
        ((short *)arg0)[3] = 1;
        ((void **)arg0)[0] = lbl_804873C0;
        ((void **)arg0)[4] = lbl_804873E8;
    }
}
}
