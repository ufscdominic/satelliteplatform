/******************************************************
 * ArchC Resources Implementation file.               *
 * This file is automatically generated by ArchC      *
 * WITHOUT WARRANTY OF ANY KIND, either express       *
 * or implied.                                        *
 * For more information on ArchC, please visit:       *
 * http://www.archc.org                               *
 *                                                    *
 * The ArchC Team                                     *
 * Computer Systems Laboratory (LSC)                  *
 * IC-UNICAMP                                         *
 * http://www.lsc.ic.unicamp.br                       *
 ******************************************************/
 

#include "msp430_arch.H"

msp430_arch::msp430_arch() :
  ac_arch_dec_if<msp430_parms::ac_word, msp430_parms::ac_Hword>(msp430_parms::AC_MAX_BUFFER),
  ac_pc("ac_pc", 0),
  DM_stg("DM_stg", 131072U),
  DM(*this, DM_stg),
  RB("RB") {

  ac_mt_endian = msp430_parms::AC_MATCH_ENDIAN;
  ac_tgt_endian = msp430_parms::AC_PROC_ENDIAN;

  IM = &DM;
  APP_MEM = &DM;

}

