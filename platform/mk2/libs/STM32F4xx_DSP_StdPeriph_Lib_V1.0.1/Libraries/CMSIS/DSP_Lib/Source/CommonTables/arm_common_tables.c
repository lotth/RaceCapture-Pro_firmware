/* ----------------------------------------------------------------------
* Copyright (C) 2010 ARM Limited. All rights reserved.
*
* $Date:        15. July 2011
* $Revision: 	V1.0.10
*
* Project: 	    CMSIS DSP Library
* Title:	    arm_common_tables.c
*
* Description:	This file has common tables like Bitreverse, reciprocal etc which are used across different functions
*
* Target Processor: Cortex-M4/Cortex-M3/Cortex-M0
*
* Version 1.0.10 2011/7/15
*    Big Endian support added and Merged M0 and M3/M4 Source code.
*
* Version 1.0.3 2010/11/29
*    Re-organized the CMSIS folders and updated documentation.
*
* Version 1.0.2 2010/11/11
*    Documentation updated.
*
* Version 1.0.1 2010/10/05
*    Production release and review comments incorporated.
*
* Version 1.0.0 2010/09/20
*    Production release and review comments incorporated.
* -------------------------------------------------------------------- */


#include "arm_math.h"

/**
 * @ingroup groupTransforms
 */

/**
 * @addtogroup CFFT_CIFFT
 * @{
 */

/**
* \par
* Pseudo code for Generation of Bit reversal Table is
* \par
* <pre>for(l=1;l <= N/4;l++)
* {
*   for(i=0;i<logN2;i++)
*   {
*     a[i]=l&(1<<i);
*   }
*   for(j=0; j<logN2; j++)
*   {
*     if (a[j]!=0)
*     y[l]+=(1<<((logN2-1)-j));
*   }
*   y[l] = y[l] >> 1;
*  } </pre>
* \par
* where N = 1024	logN2 = 10
* \par
* N is the maximum FFT Size supported
*/

/*
* @brief  Table for bit reversal process
*/
const uint16_t armBitRevTable[256] = {
        0x100, 0x80, 0x180, 0x40, 0x140, 0xc0, 0x1c0,
        0x20, 0x120, 0xa0, 0x1a0, 0x60, 0x160, 0xe0,
        0x1e0, 0x10, 0x110, 0x90, 0x190, 0x50, 0x150,
        0xd0, 0x1d0, 0x30, 0x130, 0xb0, 0x1b0, 0x70,
        0x170, 0xf0, 0x1f0, 0x8, 0x108, 0x88, 0x188,
        0x48, 0x148, 0xc8, 0x1c8, 0x28, 0x128, 0xa8,
        0x1a8, 0x68, 0x168, 0xe8, 0x1e8, 0x18, 0x118,
        0x98, 0x198, 0x58, 0x158, 0xd8, 0x1d8, 0x38,
        0x138, 0xb8, 0x1b8, 0x78, 0x178, 0xf8, 0x1f8,
        0x4, 0x104, 0x84, 0x184, 0x44, 0x144, 0xc4,
        0x1c4, 0x24, 0x124, 0xa4, 0x1a4, 0x64, 0x164,
        0xe4, 0x1e4, 0x14, 0x114, 0x94, 0x194, 0x54,
        0x154, 0xd4, 0x1d4, 0x34, 0x134, 0xb4, 0x1b4,
        0x74, 0x174, 0xf4, 0x1f4, 0xc, 0x10c, 0x8c,
        0x18c, 0x4c, 0x14c, 0xcc, 0x1cc, 0x2c, 0x12c,
        0xac, 0x1ac, 0x6c, 0x16c, 0xec, 0x1ec, 0x1c,
        0x11c, 0x9c, 0x19c, 0x5c, 0x15c, 0xdc, 0x1dc,
        0x3c, 0x13c, 0xbc, 0x1bc, 0x7c, 0x17c, 0xfc,
        0x1fc, 0x2, 0x102, 0x82, 0x182, 0x42, 0x142,
        0xc2, 0x1c2, 0x22, 0x122, 0xa2, 0x1a2, 0x62,
        0x162, 0xe2, 0x1e2, 0x12, 0x112, 0x92, 0x192,
        0x52, 0x152, 0xd2, 0x1d2, 0x32, 0x132, 0xb2,
        0x1b2, 0x72, 0x172, 0xf2, 0x1f2, 0xa, 0x10a,
        0x8a, 0x18a, 0x4a, 0x14a, 0xca, 0x1ca, 0x2a,
        0x12a, 0xaa, 0x1aa, 0x6a, 0x16a, 0xea, 0x1ea,
        0x1a, 0x11a, 0x9a, 0x19a, 0x5a, 0x15a, 0xda,
        0x1da, 0x3a, 0x13a, 0xba, 0x1ba, 0x7a, 0x17a,
        0xfa, 0x1fa, 0x6, 0x106, 0x86, 0x186, 0x46,
        0x146, 0xc6, 0x1c6, 0x26, 0x126, 0xa6, 0x1a6,
        0x66, 0x166, 0xe6, 0x1e6, 0x16, 0x116, 0x96,
        0x196, 0x56, 0x156, 0xd6, 0x1d6, 0x36, 0x136,
        0xb6, 0x1b6, 0x76, 0x176, 0xf6, 0x1f6, 0xe,
        0x10e, 0x8e, 0x18e, 0x4e, 0x14e, 0xce, 0x1ce,
        0x2e, 0x12e, 0xae, 0x1ae, 0x6e, 0x16e, 0xee,
        0x1ee, 0x1e, 0x11e, 0x9e, 0x19e, 0x5e, 0x15e,
        0xde, 0x1de, 0x3e, 0x13e, 0xbe, 0x1be, 0x7e,
        0x17e, 0xfe, 0x1fe, 0x1
};

/**
 * @} end of CFFT_CIFFT group
 */

/*
* @brief  Q15 table for reciprocal
*/
const q15_t armRecipTableQ15[64] = {
        0x7F03, 0x7D13, 0x7B31, 0x795E, 0x7798, 0x75E0,
        0x7434, 0x7294, 0x70FF, 0x6F76, 0x6DF6, 0x6C82,
        0x6B16, 0x69B5, 0x685C, 0x670C, 0x65C4, 0x6484,
        0x634C, 0x621C, 0x60F3, 0x5FD0, 0x5EB5, 0x5DA0,
        0x5C91, 0x5B88, 0x5A85, 0x5988, 0x5890, 0x579E,
        0x56B0, 0x55C8, 0x54E4, 0x5405, 0x532B, 0x5255,
        0x5183, 0x50B6, 0x4FEC, 0x4F26, 0x4E64, 0x4DA6,
        0x4CEC, 0x4C34, 0x4B81, 0x4AD0, 0x4A23, 0x4978,
        0x48D1, 0x482D, 0x478C, 0x46ED, 0x4651, 0x45B8,
        0x4521, 0x448D, 0x43FC, 0x436C, 0x42DF, 0x4255,
        0x41CC, 0x4146, 0x40C2, 0x4040
};

/*
* @brief  Q31 table for reciprocal
*/
const q31_t armRecipTableQ31[64] = {
        0x7F03F03F, 0x7D137420, 0x7B31E739, 0x795E9F94, 0x7798FD29, 0x75E06928,
        0x7434554D, 0x72943B4B, 0x70FF9C40, 0x6F760031, 0x6DF6F593, 0x6C8210E3,
        0x6B16EC3A, 0x69B526F6, 0x685C655F, 0x670C505D, 0x65C4952D, 0x6484E519,
        0x634CF53E, 0x621C7E4F, 0x60F33C61, 0x5FD0EEB3, 0x5EB55785, 0x5DA03BEB,
        0x5C9163A1, 0x5B8898E6, 0x5A85A85A, 0x598860DF, 0x58909373, 0x579E1318,
        0x56B0B4B8, 0x55C84F0B, 0x54E4BA80, 0x5405D124, 0x532B6E8F, 0x52556FD0,
        0x5183B35A, 0x50B618F3, 0x4FEC81A2, 0x4F26CFA2, 0x4E64E64E, 0x4DA6AA1D,
        0x4CEC008B, 0x4C34D010, 0x4B810016, 0x4AD078EF, 0x4A2323C4, 0x4978EA96,
        0x48D1B827, 0x482D77FE, 0x478C1657, 0x46ED801D, 0x4651A2E5, 0x45B86CE2,
        0x4521CCE1, 0x448DB244, 0x43FC0CFA, 0x436CCD78, 0x42DFE4B4, 0x42554426,
        0x41CCDDB6, 0x4146A3C6, 0x40C28923, 0x40408102
};
