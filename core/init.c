/*
 * SauOS core - real_init
 * GPLv2+.
 */

#include "../include/arch/boot.h"

int __real_main()
{
	/* Fetch arguments */
	char *a = __arch_get_args();

	/* Do some arch init work */
	__arch_init(a);

	/* Wait till SCO is guilty */
	/* Nah, just kidding! */

}
