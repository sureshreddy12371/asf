/*****************************************************************************
 *
 * \file
 *
 * \brief EIC driver for AVR32 UC3.
 *
 * AVR32 External Interrupt Controller driver module.
 *
 * Copyright (c) 2009-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 ******************************************************************************/
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */


#ifndef _EIC_H_
#define _EIC_H_

/**
 * \defgroup group_avr32_drivers_eic MEMORY - EIC - External Interrupt Controller
 *
 * EIC allows pins to be configured as external interrupts.
 *
 * \{
 */

#include "compiler.h"

/*! \name External Interrupt lines
 */
//! @{
#if (UC3A || UC3B)
#define EXT_INT0    AVR32_EIC_INT0 //!< Line 0
#define EXT_INT1    AVR32_EIC_INT1 //!< Line 1
#define EXT_INT2    AVR32_EIC_INT2 //!< Line 2
#define EXT_INT3    AVR32_EIC_INT3 //!< Line 3
#define EXT_INT4    AVR32_EIC_INT4 //!< Line 4
#define EXT_INT5    AVR32_EIC_INT5 //!< Line 5
#define EXT_INT6    AVR32_EIC_INT6 //!< Line 6
#define EXT_INT7    AVR32_EIC_INT7 //!< Line 7
#define EXT_NMI     AVR32_EIC_NMI  //!< Line 8
#else
#define EXT_INT0    AVR32_EIC_INT1  //!< Line 0
#define EXT_INT1    AVR32_EIC_INT2 //!< Line 1
#define EXT_INT2    AVR32_EIC_INT3 //!< Line 2
#define EXT_INT3    AVR32_EIC_INT4 //!< Line 3
#define EXT_INT4    AVR32_EIC_INT5 //!< Line 4
#define EXT_INT5    AVR32_EIC_INT6 //!< Line 5
#define EXT_INT6    AVR32_EIC_INT7 //!< Line 6
#define EXT_INT7    AVR32_EIC_INT8 //!< Line 7
#define EXT_NMI     AVR32_EIC_NMI  //!< Line 8

#endif


//! @}

/*! \name Mode Trigger Options
 */
//! @{
#define EIC_MODE_EDGE_TRIGGERED   AVR32_EIC_EDGE_IRQ //!<
#define EIC_MODE_LEVEL_TRIGGERED  AVR32_EIC_LEVEL_IRQ //!<
//! @}

/*! \name Edge level Options
 */
//! @{
#define EIC_EDGE_FALLING_EDGE     AVR32_EIC_FALLING_EDGE //!<
#define EIC_EDGE_RISING_EDGE      AVR32_EIC_RISING_EDGE //!<
//! @}

/*! \name Level Options
 */
//! @{
#define EIC_LEVEL_LOW_LEVEL       AVR32_EIC_LOW_LEVEL //!<
#define EIC_LEVEL_HIGH_LEVEL      AVR32_EIC_HIGH_LEVEL //!<
//! @}

/*! \name Filter Options
 */
//! @{
#define EIC_FILTER_ENABLED        AVR32_EIC_FILTER_ON //!<
#define EIC_FILTER_DISABLED       AVR32_EIC_FILTER_OFF //!<
//! @}

/*! \name Synch Mode Options
 */
//! @{
#define EIC_SYNCH_MODE            AVR32_EIC_SYNC //!<
#define EIC_ASYNCH_MODE           AVR32_EIC_USE_ASYNC //!<
//! @}

//! Configuration parameters of the EIC module.
typedef struct
{
  //!Line
  unsigned char eic_line;

  //! Mode : EDGE_LEVEL or TRIGGER_LEVEL
  unsigned char eic_mode;

  //! Edge : FALLING_EDGE or RISING_EDGE
  unsigned char eic_edge;

  //! Level :  LOW_LEVEL or HIGH_LEVEL
  unsigned char eic_level;

  //! Filter:  NOT_FILTERED or FILTERED
  unsigned char eic_filter;

  //! Async:  SYNC mode or ASYNC
  unsigned char eic_async;

} eic_options_t;


/*! \brief Init the EIC driver.
 *
 * \param eic Base address of the EIC module
 * \param opt Configuration parameters of the EIC module (see \ref eic_options_t)
 * \param nb_lines Number of lines to consider, equal to size of opt buffer
 */
extern void eic_init(volatile avr32_eic_t *eic, const eic_options_t *opt, uint32_t nb_lines);

/*! \brief Enable the EIC driver.
 *
 * \param eic Base address of the EIC module
 * \param mask_lines Mask for current selected lines
 */
extern void eic_enable_lines(volatile avr32_eic_t *eic, uint32_t mask_lines);

/*! \brief Enable the EIC driver.
 *
 * \param eic Base address of the EIC module
 * \param line_number Line number to enable
 */
extern void eic_enable_line(volatile avr32_eic_t *eic, uint32_t line_number);

/*! \brief Disable the EIC driver.
 *
 * \param eic Base address of the EIC module
 * \param mask_lines Mask for current selected lines
 */
extern void eic_disable_lines(volatile avr32_eic_t *eic, uint32_t mask_lines);

/*! \brief Disable the EIC driver.
 *
 * \param eic Base address of the EIC module
 * \param line_number Line number to disable
 */
extern void eic_disable_line(volatile avr32_eic_t *eic, uint32_t line_number);

/*! \brief Tells whether an EIC line is enabled.
 *
 * \param eic Base address of the EIC module
 * \param line_number Line number to test
 *
 * \return Whether an EIC line is enabled.
 */
extern bool eic_is_line_enabled(volatile avr32_eic_t *eic, uint32_t line_number);

/*! \name Interrupt Control Functions
 */
//! @{

/*! \brief Enable the interrupt feature of the EIC.
 *
 * \param eic Base address of the EIC (i.e. &AVR32_EIC).
 * \param mask_lines Mask for current selected lines
 */
extern void eic_enable_interrupt_lines(volatile avr32_eic_t *eic, uint32_t mask_lines);

/*! \brief Enable the interrupt feature of the EIC.
 *
 * \param eic Base address of the EIC (i.e. &AVR32_EIC).
 * \param line_number Line number to enable
 */
extern void eic_enable_interrupt_line(volatile avr32_eic_t *eic, uint32_t line_number);

/*! \brief Disable the interrupt feature of the EIC.
 *
 * \param eic Base address of the EIC (i.e. &AVR32_EIC).
 * \param mask_lines Mask for current selected lines
 */
extern void eic_disable_interrupt_lines(volatile avr32_eic_t *eic, uint32_t mask_lines);

/*! \brief Disable the interrupt feature of the EIC.
 *
 * \param eic Base address of the EIC (i.e. &AVR32_EIC).
 * \param line_number Line number to disable
 */
extern void eic_disable_interrupt_line(volatile avr32_eic_t *eic, uint32_t line_number);

/*! \brief Tells whether an EIC interrupt line is enabled.
 *
 * \param eic Base address of the EIC module
 * \param line_number Line number to test
 *
 * \return Whether an EIC interrupt line is enabled.
 */
extern bool eic_is_interrupt_line_enabled(volatile avr32_eic_t *eic, uint32_t line_number);

/*! \brief Clear the interrupt flag.
 *         Call this function once you've handled the interrupt.
 *
 * \param eic Base address of the EIC (i.e. &AVR32_EIC).
 * \param mask_lines Mask for current selected lines
 */
extern void eic_clear_interrupt_lines(volatile avr32_eic_t *eic, uint32_t mask_lines);

/*! \brief Clear the interrupt flag.
 *         Call this function once you've handled the interrupt.
 *
 * \param eic Base address of the EIC (i.e. &AVR32_EIC).
 * \param line_number Line number to clear
 */
extern void eic_clear_interrupt_line(volatile avr32_eic_t *eic, uint32_t line_number);

/*! \brief Tells whether an EIC interrupt line is pending.
 *
 * \param eic Base address of the EIC module
 * \param line_number Line number to test
 *
 * \return Whether an EIC interrupt line is pending.
 */
extern bool eic_is_interrupt_line_pending(volatile avr32_eic_t *eic, uint32_t line_number);

/*! \brief Enable the interrupt scan feature of the EIC.
 *
 * \param eic Base address of the EIC (i.e. &AVR32_EIC).
 * \param presc Prescale select for the keypad scan rate in the range [0,31].
 */
extern void eic_enable_interrupt_scan(volatile avr32_eic_t *eic, uint32_t presc);

/*! \brief Disable the interrupt scan feature of the EIC.
 *
 * \param eic Base address of the EIC (i.e. &AVR32_EIC).
 */
extern void eic_disable_interrupt_scan(volatile avr32_eic_t *eic);

/*! \brief Return scan pad number that causes interrupt.
 *
 * \param eic Base address of the EIC (i.e. &AVR32_EIC).
 */
extern uint32_t eic_get_interrupt_pad_scan(volatile avr32_eic_t *eic);

//! @}

/**
 * \}
 */

#endif  // _EIC_H_
