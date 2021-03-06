/******************************************************
 * This is the main file for the msp430 ArchC model   *
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

const char* project_name = "msp430";
const char* project_file = "msp430.ac";
const char* archc_version = "2.2";
const char* archc_options = "";

#include <systemc.h>
//#include "ac_stats_base.h"
#include "msp430.H"

int sc_main(int ac, char** av)
{
 //! Clock.
 sc_clock clk("clk", 20, 0.5, true);
 //! ISA simulator.
 msp430 msp430_p0("msp430", clk.period().to_double());

 msp430_p0.clock(clk);
#ifdef AC_DEBUG
 ac_trace("msp430.trace");
#endif
 msp430_p0.init(ac, av);
 sc_start(); // Starts SystemC simulation.
#ifdef AC_STATS
 ac_stats_base::print_all_stats(std::cerr);
#endif
#ifdef AC_DEBUG
 ac_close_trace();
#endif
 return msp430_p0.ac_exit_status;
}
