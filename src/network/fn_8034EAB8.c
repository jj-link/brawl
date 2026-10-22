#pragma force_active on
extern void *lbl_805A0FB0;

void fn_8034EAB8(int arg0)
{
    int off;

    if (lbl_805A0FB0 == 0) {
        return;
    }
    off = arg0 * 0x48;
    *(int *)((char *)lbl_805A0FB0 + off + 0xC) = 0;
    *(int *)((char *)lbl_805A0FB0 + off + 0x10) = 0;
    *(int *)((char *)lbl_805A0FB0 + off + 0x14) = 0;
    *(int *)((char *)lbl_805A0FB0 + off + 0x18) = 0;
    *(unsigned char *)((char *)lbl_805A0FB0 + off + 0x1C) = 0;
    if (*(unsigned char *)((char *)lbl_805A0FB0 + off + 0x1D) != 0) {
        *(unsigned char *)((char *)lbl_805A0FB0 + off + 0x1D) = 1;
    }
    *(short *)((char *)lbl_805A0FB0 + off + 0x22) = 0;
}
