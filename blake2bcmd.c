/*
 BLAKE2b reference implementation reading from stdin and printing hash.
 By modrobert@gmail.com in 2019.
*/

#include <stdio.h>
#include <unistd.h>

#include "blake2b.h"

#define BUFSIZE 1 /* Read buffer size. */
#define MDSIZE 64 /* Message digest 512 bit. */

int main()
{
 uint8_t md[MDSIZE];
 blake2b_ctx ctx;

 uint8_t buf[BUFSIZE];
 size_t i;

 /* Initialize blake2b hashing context. */
 if (blake2b_init(&ctx, MDSIZE, NULL, 0))
  return -1;

 /* Read from stdin. */
 while (read(STDIN_FILENO, buf, BUFSIZE) > 0)
 {
  blake2b_update(&ctx, buf, BUFSIZE);
 }

 /* Final round. */
 blake2b_final(&ctx, md);

 /* Print result hash. */
 for (i = 0; i < MDSIZE; i++)
 {
  printf("%02x", md[i]);
 }
 printf("\n");

 return 0;
}

/* vim:ts=1:sw=1:ft=c:et:ai:
*/
