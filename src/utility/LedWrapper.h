////////////////////////////////////////////////////////////////////////////////
// /****************************************************************************
// **
// ** Copyright (C) 2015-2022 M-Way Solutions GmbH
// ** Contact: https://www.blureange.io/licensing
// **
// ** This file is part of the Bluerange/FruityMesh implementation
// **
// ** $BR_BEGIN_LICENSE:GPL-EXCEPT$
// ** Commercial License Usage
// ** Licensees holding valid commercial Bluerange licenses may use this file in
// ** accordance with the commercial license agreement provided with the
// ** Software or, alternatively, in accordance with the terms contained in
// ** a written agreement between them and M-Way Solutions GmbH.
// ** For licensing terms and conditions see https://www.bluerange.io/terms-conditions. For further
// ** information use the contact form at https://www.bluerange.io/contact.
// **
// ** GNU General Public License Usage
// ** Alternatively, this file may be used under the terms of the GNU
// ** General Public License version 3 as published by the Free Software
// ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
// ** included in the packaging of this file. Please review the following
// ** information to ensure the GNU General Public License requirements will
// ** be met: https://www.gnu.org/licenses/gpl-3.0.html.
// **
// ** $BR_END_LICENSE$
// **
// ****************************************************************************/
////////////////////////////////////////////////////////////////////////////////

/*
 * The LED Wrapper provides convenient access to LEDs
 * Thanks to Torbjorn Ovrebekk.
 * https://devzone.nordicsemi.com/question/18377/c-development-using-nrf51-sdk-on-keil/
 * */
#pragma once

#include <FmTypes.h>


class LedWrapper
{
private: 
    u32 m_io_pin;
    bool m_active_high;
    bool active;

public:
    LedWrapper(i8 io_num, bool active_high);
    LedWrapper();
    void Init(i8 io_num, bool active_high);
    void On(void);
    void Off(void);
    void Toggle(void);


    // Non-blocking! Must be called repeatedly.
    // Will pulse the LED on/off each time it is called
    // until the given amount of pulses in the given cycle time
    // is reached.
    void Pulse(u32 amountOfPulses, u32 repeatTimeDs);
};

