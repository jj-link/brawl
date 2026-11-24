#pragma force_active on

extern int lbl_805A1170;
extern int fn_80398818(void *, unsigned int, unsigned int);
extern int fn_80398A08(void *, int, void *);
extern int fn_8039D45C(unsigned char *, int, signed char *, unsigned int, unsigned int *);
int fn_803A001C(void *context, int *range, signed char *arg2, unsigned int capacity, unsigned int *written)
{
  int new_var;
  {
    unsigned int *savedWritten = written;
    unsigned int savedCapacity = capacity;
    void *savedContext = context;
    int count;
    int remaining = range[1];
    int offset = range[0];
    unsigned char *buffer = (unsigned char *) (lbl_805A1170 + 0x400);
    signed char *out = arg2;
    unsigned int total = 0;
    int used;
    int result = 0;
    int done = 0;
    unsigned int produced;
    while ((remaining > 0) && (!done))
    {
      unsigned int c;
      count = 0x400;
      if (remaining <= 0x400)
      {
        count = remaining;
      }
      fn_80398818(savedContext, offset, 0);
      result = fn_80398A08(buffer, count, savedContext);
      if (result != 0)
      {
        break;
      }
      written = (unsigned int *) buffer;
      used = 0;
      for (capacity = 0; ((int) capacity) < count; capacity++, written = (unsigned int *) (((unsigned char *) written) + (new_var = 1)))
      {
        if (((int) ((char) (c = *((unsigned char *) written)))) == 13)
        {
          used = capacity;
        }
        if (((signed char) c) == '=')
        {
          used = capacity + new_var;
          done = new_var;
          result = 0;
          break;
        }
      }

      if (used == 0)
      {
        break;
      }
      result = fn_8039D45C(buffer, used, out, savedCapacity - total, &produced);
      if (result != 0)
      {
        break;
      }
      offset += used;
      remaining -= used;
      total += produced;
      out += produced;
    }

    if (result == 0)
    {
      *savedWritten = total;
    }
    return result;
  }
}
