/*
 BLAKE2b reference implementation reading from stdin and printing hash.
 By modrobert@gmail.com in 2019.
*/

#include <stdio.h>
#include <unistd.h>

#include "blake2b.h"

int main()
{
 uint8_t md[64];
 blake2b_ctx ctx;

 uint8_t buf[1];
 size_t i;

 /* Init blacke2b, set 512 bit (8 * 64). */
 if (blake2b_init(&ctx, 64, NULL, 0))
  return -1;

 /* Read from stdin. */
 while (read(STDIN_FILENO, buf, sizeof(buf)) > 0)
 {
  blake2b_update(&ctx, buf, 1);
 }

 /* Final round. */
 blake2b_final(&ctx, md);

 /* Print result hash. */
 for (i = 0; i < 64; i++)
 {
  printf("%02x", md[i]);
 }
 printf("\n");

 return 0;
}

/* vim:ts=1:sw=1:ft=c:et:ai:
*/
