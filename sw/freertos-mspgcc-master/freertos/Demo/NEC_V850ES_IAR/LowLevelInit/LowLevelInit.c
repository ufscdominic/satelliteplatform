/*
    FreeRTOS V7.1.1 - Copyright (C) 2012 Real Time Engineers Ltd.
	

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS tutorial books are available in pdf and paperback.        *
     *    Complete, revised, and edited pdf reference manuals are also       *
     *    available.                                                         *
     *                                                                       *
     *    Purchasing FreeRTOS documentation will not only help you, by       *
     *    ensuring you get running as quickly as possible and with an        *
     *    in-depth knowledge of how to use FreeRTOS, it will also help       *
     *    the FreeRTOS project to continue with its mission of providing     *
     *    professional grade, cross platform, de facto standard solutions    *
     *    for microcontrollers - completely free of charge!                  *
     *                                                                       *
     *    >>> See http://www.FreeRTOS.org/Documentation for details. <<<     *
     *                                                                       *
     *    Thank you for using FreeRTOS, and thank you for your support!      *
     *                                                                       *
    ***************************************************************************


    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
    >>>NOTE<<< The modification to the GPL is included to allow you to
    distribute a combined work that includes FreeRTOS without being obliged to
    provide the source code for proprietary components outside of the FreeRTOS
    kernel.  FreeRTOS is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details. You should have received a copy of the GNU General Public
    License and the FreeRTOS license exception along with FreeRTOS; if not it
    can be viewed here: http://www.freertos.org/a00114.html and also obtained
    by writing to Richard Barry, contact details for whom are available on the
    FreeRTOS WEB site.

    1 tab == 4 spaces!
    
    ***************************************************************************
     *                                                                       *
     *    Having a problem?  Start by reading the FAQ "My application does   *
     *    not run, what could be wrong?                                      *
     *                                                                       *
     *    http://www.FreeRTOS.org/FAQHelp.html                               *
     *                                                                       *
    ***************************************************************************

    
    http://www.FreeRTOS.org - Documentation, training, latest information, 
    license and contact details.
    
    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool.

    Real Time Engineers ltd license FreeRTOS to High Integrity Systems, who sell 
    the code with commercial support, indemnification, and middleware, under 
    the OpenRTOS brand: http://www.OpenRTOS.com.  High Integrity Systems also
    provide a safety engineered and independently SIL3 certified version under 
    the SafeRTOS brand: http://www.SafeRTOS.com.
*/

#include "FreeRTOS.h"

/*-----------------------------------------------------------*/

/* Called by the startup code to initialise the run time system. */
unsigned portCHAR __low_level_init(void);

/*-----------------------------------------------------------*/

unsigned portCHAR __low_level_init(void)
{
unsigned portCHAR resetflag = RESF;
unsigned portCHAR psval = 0;
unsigned portBASE_TYPE i = 0;        

	/* Setup provided by NEC. */

	portDISABLE_INTERRUPTS();         /* disable global interrupts */                      

	PRCMD = 0x00;                     /* On-chip debug mode */
	OCDM = 0x00;
	VSWC = 0x00;                      /* set system wait control register */
	WDTM2 = 0x00;                     /* WDT2 setting */
	PLLON = 0;                        /* PLL stop mode */
	psval = 0x0A | 0x00;
	PRCMD = psval;                    /* set Command Register */
	CKC = psval;                      /* set Clock Control Register */
	PLLS = 0x03;
	psval = 0x80;                     /* Set fXX and fCPU */
	PRCMD = psval;
	PCC = psval;
	PLLON = 1;                        /* activate PLL */
	for( i = 0; i <= 2000; i++ )      /* Wait for stabilisation */
	{
	portNOP();
	}
	while( LOCK )                     /* Wait for PLL frequency stabiliasation */
	{
	;
	}
	SELPLL = 1;                       /* Set PLL mode active */
	RSTOP = 0;                        /* Set fR (enable) */
	BGCE0 = 0;                        /* Set fBRG(disable) */
	psval = 0x00;                     /* Stand-by setting */
	PRCMD = psval;                    /* set Command Register */
	PSC = psval;                      /* set Power Save Control Register */

	return pdTRUE;
}
/*-----------------------------------------------------------*/
