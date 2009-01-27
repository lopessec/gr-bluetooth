/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef INCLUDED_BLUETOOTH_MULTI_HOPPER_H
#define INCLUDED_BLUETOOTH_MULTI_HOPPER_H

#include "bluetooth_multi_block.h"
#include "bluetooth_piconet.h"

class bluetooth_multi_hopper;
typedef boost::shared_ptr<bluetooth_multi_hopper> bluetooth_multi_hopper_sptr;

/*!
 * \brief Return a shared_ptr to a new instance of bluetooth_multi_hopper.
 */
bluetooth_multi_hopper_sptr bluetooth_make_multi_hopper(double sample_rate, double center_freq, int squelch_threshold, int LAP);

/*!
 * \brief Sniff Bluetooth packets.
 * \ingroup block
 */
class bluetooth_multi_hopper : public bluetooth_multi_block
{
private:
	// The friend declaration allows bluetooth_make_multi_hopper to
	// access the private constructor.
	friend bluetooth_multi_hopper_sptr bluetooth_make_multi_hopper(double sample_rate, double center_freq, int squelch_threshold, int LAP);

	/* constructor */
	bluetooth_multi_hopper(double sample_rate, double center_freq, int squelch_threshold, int LAP);

	/* do we have CLK1-6? */
	bool d_have_clock6;

    /* remember the time slot of the previous packet for interval computation */
	int d_previous_slot;

	/* LAP of the target piconet */
	uint32_t d_LAP;

	/* the piconet we are monitoring */
	bluetooth_piconet_sptr d_piconet;

public:
	/* destructor */
	~bluetooth_multi_hopper();

	/* handle input */
	int work(int noutput_items,
		    gr_vector_const_void_star &input_items,
		    gr_vector_void_star &output_items);
};

#endif /* INCLUDED_BLUETOOTH_MULTI_HOPPER_H */
