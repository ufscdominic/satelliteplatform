/**
 * @file   counter.cpp
 *
 * @author Dominic Zijlstra <dominiczijlstra@gmail.com> 
 * @date   Mon Jun 1 13:29:20 2015
 *
 * @brief  This file implements a timer/counter module
 * 
 */

#include "counter.h"
#include <iostream>
#include "ac_debug_model.H"
using std::cout;
using std::endl;

Counter::Counter(sc_module_name name, int start): sc_module(name), value(start) {
  req= new ac_tlm_req; 
  rsp= new ac_tlm_rsp; 
  SC_THREAD(event_trigger_thread);

  SC_METHOD(count_method);
  dont_initialize();
  sensitive << count_event;
}

void Counter::count_method() {
	if (read_register(TA0CTL_) & TACLR){ // clear
		write_register(TAR_ , 0); // reset tar
		write_register(TA0CTL_, (read_register(TA0CTL_) & !(TACLR)) & !(MC_1) ); // reset clear, mode
		
	} else if (read_register(TACTL_)& MC_1) { // up mode
		value=read_register(TAR_); // read reg
		value++; // increase
		write_register(TAR_ , value); // write to reg

		if (value == read_register(TACCR0_)){ // compare
			ccifg_interrupt(); // interrupt
			write_register(TAR_ , 0); // write 0 to reg
		}

	}


}

void Counter::event_trigger_thread() {
  for (;;) { // infinite loop
    wait(30517578,SC_PS); // aclk has freq 32768 Hz > 30517578 SC_PS
    // then immediately trigger "count_method" through "count_event"
    dbg_printf("Counting\n");
    count_event.notify();
  }
}
