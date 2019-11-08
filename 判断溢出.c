//判断(req+2*MINSIZE)是否溢出
#define REQUEST_OUT_OF_RANGE(req)                                 \
  ((unsigned long)(req) >=                                        \
   (unsigned long)(unsigned int)(-2 * MINSIZE))