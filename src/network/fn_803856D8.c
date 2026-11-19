#pragma force_active on

typedef enum _va_arg_type
{
  arg_ARGPOINTER,
  arg_WORD,
  arg_DOUBLEWORD,
  arg_ARGREAL
} _va_arg_type;
typedef struct __va_list_struct
{
  char gpr;
  char fpr;
  char *input_arg_area;
  char *reg_save_area;
} va_list[1];
void *__va_arg(va_list argp, int type);
typedef signed long intptr_t;
typedef unsigned long uintptr_t;
typedef intptr_t ptrdiff_t;
typedef unsigned long size_t;
typedef unsigned short wchar_t;
typedef unsigned long long u64;
typedef signed long long s64;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
typedef double f64;
typedef int UNKWORD;
typedef void UNKTYPE;
enum 
{
  FALSE,
  TRUE
};
typedef int BOOL;
typedef void (*funcptr_t)(void);
int stricmp(const char *, const char *);
char *itoa(int value, char *str, int base);
void *memcpy(void *, const void *, size_t);
void *memset(void *, int, size_t);
void *memfill(const void *, int, size_t);
void *__memfill(const void *, int, size_t);
void *memmove(void *, const void *, size_t);
void *memchr(const void *, int, size_t);
void *__memrchr(const void *, int, size_t);
int memcmp(const void *, const void *, size_t);
char *strcpy(char *, const char *);
char *strncpy(char *, const char *, size_t);
char *strcat(char *, const char *);
char *strncat(char *, const char *, size_t);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, size_t);
char *strchr(const char *, int);
char *strstr(const char *, const char *);
size_t strlen(const char *);
extern s32 lbl_805A10D4;
extern s32 lbl_805A10D8;
extern s32 lbl_805A10DC;
extern s32 lbl_805A10E0;
extern s32 lbl_805A10E4;
extern s32 lbl_805A10E8;
extern s32 lbl_805A10EC;
extern u8 lbl_80536020[0x200];
extern u8 lbl_8059FB68[];
extern u16 SONtoHs(u16);
extern int CanReceiveOnSocket(int);
extern int recvfrom(int, void *, u32, int, void *, u32 *);
extern int getsockname(int, void *, u32 *);
extern void fn_8035C658(int);
extern int fn_803F6150(void *, void *, int);
extern int fn_803A7AF4(int);
extern int fn_8038563C(void);
extern void fn_80385558(int, u16, int);
int fn_803856D8(int socket, u8 *out)
{
  u32 len;
  unsigned char new_var;
  u32 socklen;
  struct 
  {
    u16 family;
    u16 port;
    s32 addr;
  } from;
  u8 local[8];
  u8 packet[0x4c];
  s32 received;
  s32 port;
  s32 idx;
  u8 type;
  u8 *p;
  len = 8;
  if ((((((lbl_805A10EC && lbl_805A10E8) && lbl_805A10E4) && lbl_805A10E0) && lbl_805A10DC) && lbl_805A10D8) && lbl_805A10D4)
  {
    return 0;
  }
  if (socket != (-1))
  {
    do
    {
      if (!CanReceiveOnSocket(socket))
      {
        break;
      }
      received = recvfrom(socket, lbl_80536020, 0x200, 0, &from, &len);
      if (received == (-1))
      {
        fn_8035C658(socket);
        break;
      }
      if (fn_803F6150(lbl_80536020, lbl_8059FB68, 6))
      {
        return 1;
      }
      type = lbl_80536020[7];
      if (received < 0x15)
      {
        return 1;
      }
      if (type == 2)
      {
        memcpy(packet, lbl_80536020, 0x15);
        switch (packet[12])
        {
          case 1:
            lbl_805A10EC = 1;
            new_var = 0;
            fn_80385558(from.addr, SONtoHs(from.port), new_var);
            break;

          case 2:
            lbl_805A10EC = lbl_805A10EC;
            *((s32 *) (out + 0x80)) = 0;
            lbl_805A10E8 = 1;
            fn_80385558(from.addr, SONtoHs(from.port), new_var);
            break;

          case 3:
            *((s32 *) (out + 0x84)) = 0;
            lbl_805A10E4 = 1;
            fn_80385558(from.addr, SONtoHs(from.port), 0);
            break;

        }

      }
      else
        if (type == 11)
      {
        memcpy(packet, lbl_80536020, 0x15);
        idx = fn_803A7AF4(*((s32 *) (packet + 8)));
        *((s32 *) (packet + 8)) = idx;
        switch (idx)
        {
          case 0:
            lbl_805A10E0 = 1;
            break;

          case 3:
            lbl_805A10DC = 1;
            break;

          case 1:
            lbl_805A10D8 = 1;
            break;

          case 2:
            lbl_805A10D4 = 1;
            break;

        }

        *((s32 *) ((out + ((*((s32 *) (packet + 8))) * 16)) + 0x94)) = fn_8038563C();
        socklen = 8;
        if (getsockname(socket, local, &socklen) == (-1))
        {
          port = 0;
        }
        else
        {
          port = *((u16 *) (local + 2));
        }
        *((u16 *) ((out + ((*((s32 *) (packet + 8))) * 16)) + 0x98)) = SONtoHs(port);
        *((s32 *) ((out + ((*((s32 *) (packet + 8))) * 16)) + 0x9c)) = *((s32 *) (packet + 15));
        *((u16 *) ((out + ((*((s32 *) (packet + 8))) * 16)) + 0xa0)) = SONtoHs(*((u16 *) (packet + 19)));
        fn_80385558(from.addr, SONtoHs(from.port), new_var);
        p = &((struct 
        {
          u8 padding[0x94];
          u8 entry[16];
        } *) (out + ((*((s32 *) (packet + 8))) * 16)))->entry[new_var];
        if (p == 0)
        {
          if ((!lbl_805A10EC) && (!lbl_805A10EC))
          {
          }
        }
        else
        {
          fn_80385558(*((s32 *) p), *((u16 *) (p + 4)), 0);
          fn_80385558(*((s32 *) (p + 8)), *((u16 *) (p + 12)), 0);
        }
      }
    }
    while (socket != (-1));
  }
  return 1;
}
